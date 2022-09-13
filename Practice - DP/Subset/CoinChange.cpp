//LeetCode - 322. Coin Change.
//You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
// Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

// You may assume that you have an infinite number of each kind of coin.

//The question is similar to subset sum, just we need to concentrate to take minimum members from the subset.

#include<iostream>
#include<vector>
using namespace std;

class Solution{
private:
    int find(int index, int target, vector<int> &array, vector<vector<int>> &dp){
        if(target==0) return 0;
        if(index==0){
            if((target%array[0])==0) return (target/array[0]);
            else return 1e9;
        }

        if(dp[index][target]!=-1)   return dp[index][target];
        int take=1e9;   //If target!=0 && target < value: Do not consider the case.
        if(target>=array[index]) take = 1 + find(index, target-array[index], array, dp);
        int notTake = 0 + find(index-1, target, array, dp);

        return dp[index][target] = min(take, notTake); 
    }

public:
    int findMinCoins(vector<int> &array, int sum){
        int n = array.size();
        vector<vector<int>> dp(n, vector<int>(sum+1, -1));

        int mini = find(n-1, sum, array, dp);
        if(mini==1e9) return -1;    //Check if its it possible to attain the value.
        else return mini;
    }
};

int main(){
    vector<int> array = {1,2,5};
    Solution find;
    cout << find.findMinCoins(array, 11);
    return 0;
}