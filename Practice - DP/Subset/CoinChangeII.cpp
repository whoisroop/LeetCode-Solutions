// LeetCode - 518. Coin Change II 
//You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

// Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

// You may assume that you have an infinite number of each kind of coin.

//The question is similar to subset sum, just we need to concentrate on number of ways we can achieve the target.

#include<iostream>
#include<vector>
using namespace std;

class Solution{
private:
    int find(int index, int target, vector<int> &array, vector<vector<int>> &dp){
        if(target==0) return 1;
        if(index==0){
            if((target%array[0])==0) return 1;
            else return 0;
        }

        if(dp[index][target]!=-1)   return dp[index][target];
        int take=0;   //If target!=0 && target < value: Do not consider the case.
        if(target>=array[index]) take = find(index, target-array[index], array, dp);
        int notTake = find(index-1, target, array, dp);

        return dp[index][target] = (take+notTake); 
    }

public:
    int findWays(vector<int> &array, int sum){
        int n = array.size();
        vector<vector<int>> dp(n, vector<int>(sum+1, -1));

        return find(n-1, sum, array, dp);
    }
};

int main(){
    vector<int> array = {1,2,3};
    Solution find;
    cout << find.findWays(array, 4);
    return 0;
}