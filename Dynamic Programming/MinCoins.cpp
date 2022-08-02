#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    int f(int index, int target, vector<int> coins, vector<vector<int>> &dp){
        if(index==0){
            if(target%coins[0]==0)  return (target/coins[0]);
            else return 1e8;
        }

        if(dp[index][target]!=-1)   return dp[index][target];

        int notTake = 0 + f(index-1, target, coins, dp);
        int take = 1e8;
        if(target>=coins[index])    take = 1 + f(index, target-coins[index], coins, dp);

        return (dp[index][target] = min(take, notTake));
    }

    int findMinCoins(vector<int> coins, int amount){
        int n = coins.size()-1;
        vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));

        int ans = f(n, amount, coins, dp);
        if(ans>=1e8)    return -1;
        else    return ans;
    }

    int optimized(vector<int> coins, int amount){
        int n = coins.size()-1;
        vector<int> curr(amount+1, 0), prev(amount+1, 0);

        //BASE CASE
        for(int tar=0; tar<=amount; tar++){
            if(tar%coins[0]==0) prev[tar] = (tar/coins[0]);
            else    prev[tar] = 1e8;
        }

        for(int index=1; index<=n; index++){
            for(int target=0; target<=amount; target++){
                int notTake = 0 + prev[target];
                int take = 1e8;
                if(target>=coins[index])    take = 1 + curr[target-coins[index]];

                curr[target] = min(take, notTake);
            }
            prev = curr;
        }

        if(prev[amount]<1e8)  return prev[amount];
        else return -1;
    }

};

int main(){
    vector<int> coins = {3,5,9};
    int sum = 17;
    Solution newSol;
    cout << newSol.optimized(coins, sum);

    return 0;
}