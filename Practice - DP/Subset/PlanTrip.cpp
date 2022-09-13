// LeetCode - 983. Minimum cost of tickets.
// You have planned some train traveling one year in advance. The days of the year in which you will travel are given as an integer array days. Each day is an integer from 1 to 365.

// Train tickets are sold in three different ways:

// a 1-day pass is sold for pass[0] dollars,
// a 7-day pass is sold for pass[1] dollars, &
// a 30-day pass is sold for pass[2] dollars.
// The passes allow that many days of consecutive travel.

#include<iostream>
#include<vector>
using namespace std;

class Solution{
private:
    int find(int index, int rDays, vector<int> &days, vector<int> &pass, vector<vector<int>> &dp){
        if(index<0) return 0;

        if(dp[index][rDays]!=-1) return dp[index][rDays];
        int cost = 0;
        //Check if the in pass is valid at days[index]: If remaining days >= days passed since last used.
        if(index!=(days.size()-1) && rDays>=(days[index+1]-days[index])){
            //If it is valid decrease the remaining days by the days that have passed & do not add any value to the cost.
            cost = 0 + find(index-1, rDays-(days[index+1]-days[index]), days, pass, dp);
        }
        //If the pass expired: Choose from any of the three passes (try all ways).
        else{
            int pathA = pass[0] + find(index-1, 0, days, pass, dp); //1-1
            int pathB = pass[1] + find(index-1, 6, days, pass, dp); //7-1
            int pathC = pass[2] + find(index-1, 29, days, pass, dp); //30-1

            cost = min(pathA, min(pathB, pathC));
        }

        return dp[index][rDays] = cost;
    }

public:
    int mincostTickets(vector<int> &days, vector<int> &pass){
        int n = days.size();
        vector<vector<int>> dp(n, vector<int>(30, -1));
        return find(n-1, 0, days, pass, dp);
    }
};

int main(){
    vector<int> array = {1,2,3,4,5,6,7,8,9,10,30,31};
    vector<int> pass = {2,7,15};
    Solution find;
    cout << find.mincostTickets(array, pass);
    return 0;
}