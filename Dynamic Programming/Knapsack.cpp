//Classical Knapsack Problem
#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    int maxValue(int index, int capacity, vector<vector<int>> item, vector<vector<int>> &dp){
        int value=0, weight=1;

        if(index==0){
            if(item[index][weight]<=capacity)   return item[index][value];  //Last item will be stolen if it can fit to maximize the value;
            else    return 0;
        }

        if(dp[index][capacity]!=-1) return dp[index][capacity];

        int take = -1e8;
        if(item[index][weight]<=capacity) take = item[index][value] + maxValue(index-1, (capacity - item[index][weight]), item, dp);

        int notTake = maxValue(index-1, capacity, item, dp);
        return dp[index][capacity] = max(take, notTake);
    }

    int knapsack(vector<vector<int>> item, int maxWeight){
        int lastIndex = item.size()-1;
        vector<vector<int>> dp(lastIndex+1, vector<int>(maxWeight+1, -1));  //Index & Capacity: Variables
        int value = maxValue(lastIndex, maxWeight, item, dp);
        return value;
    }


};

int main(){
    vector<vector<int>> item = {{30,3},{40,2},{60,5}};
    int maxWeight = 6;
    Solution newSol;
    cout << newSol.knapsack(item, maxWeight);
}