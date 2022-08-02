//Ninja can perform one of 3 tasks such that no two days the same task is performed for N days.
//Find the max points he can earn. Points for each day is different.
//day - current day, last - task performed on last day.
#include<iostream>
#include<vector>
using namespace std;

class Solution{
    vector<int> sequence;
    public:
    int f(int day, int last, vector<vector<int>> points, vector<vector<int>> &dp){
        int n = points[0].size() - 1; //Last Index  (n: total tasks - 1 [task0, task1, task2])

        if(day == 0){
            int maxi = 0;
            for(int task=0; task<=n; task++){
                if(task!=last) maxi = max(maxi, points[0][task]);
            }

            return maxi;
        }

        if(dp[day][last] != -1) return dp[day][last];

        int maxi=0;
        for(int task=0; task<=n; task++){
            if(task!=last){
                int point = points[day][task] + f(day-1, task, points, dp); //Find the branch values.
                maxi = max(point, maxi);    //Consider the max branch value.
            }
        }

        return dp[day][last] = maxi;
    }


    int ninja(vector<vector<int>> points){
        int days = points.size();
        int tasks = points[0].size();    //Initially none of the task was performed.
        vector<vector<int>> dp(days, vector<int>(tasks + 1, -1));

        return f(days-1, tasks, points, dp);
    }
};

int main(){
    int totalDays = 4;
    int totalTasks = 3;
    vector<vector<int>> points(totalDays, vector<int>(totalTasks, -1)); // 4x3

    points = {{2,1,3}, {3,4,6}, {10,1,6}, {8,3,7}};

    Solution newSol;
    cout << newSol.ninja(points);

    return 0;
}