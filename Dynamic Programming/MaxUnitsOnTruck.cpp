// You are assigned to put some amount of boxes onto one truck. You are given a 2D array boxTypes, where boxTypes[i] = [numberOfBoxesi, numberOfUnitsPerBoxi]:

// numberOfBoxesi is the number of boxes of type i.
// numberOfUnitsPerBoxi is the number of units in each box of the type i.
// You are also given an integer truckSize, which is the maximum number of boxes that can be put on the truck. You can choose any boxes to put on the truck as long as the number of boxes does not exceed truckSize.

// Return the maximum total number of units that can be put on the truck.

#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    int f(int index, int capacity, vector<vector<int>> item, vector<vector<vector<int>>> &dp){
        int boxes = 0;
        int units = 1;
        if(index==0){
            if(capacity==0) return 0;
            if(capacity>=item[0][boxes])   return item[0][boxes]*item[0][units];
            else   return capacity*item[0][units];
        }

        if(dp[index][capacity][item[index][boxes]] !=-1) return dp[index][capacity][item[index][boxes]];
        
        int notTake = 0 + f(index-1, capacity, item, dp);
        int take = -1e8;
        if(item[index][boxes]>0 && capacity>0){
            item[index][boxes]--;
            take = item[index][units] + f(index, capacity-1, item, dp);
        }

        return dp[index][capacity][item[index][boxes]] = max(take, notTake);
    }

    int maxUnits(vector<vector<int>> item, int maxCapacity){
        int n = item.size()-1;
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(maxCapacity+1, vector<int>(1001, -1)));

        return f(n, maxCapacity, item, dp);
    }

};

int main(){
    vector<vector<int>> item = {{1,3},{2,2},{3,1}};
    int truckSize = 4;
    
    Solution newSol;
    cout << newSol.maxUnits(item, truckSize);

    return 0;
}