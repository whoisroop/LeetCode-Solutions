#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int f(int i, int li, vector<int> &coins, vector<int> &dp){
        if(i>li)    return 0;

        if(dp[i]!=-1)   return dp[i];

        int notRob = 0 + f(i+1, li, coins, dp);
        int rob = coins[i] + f(i+2, li, coins, dp);

        return dp[i] = max(rob, notRob);
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, -1);
        int a = f(0, n-2, nums, dp);

        //Reset the dp vector
        for(int &i: dp) i = -1;
        int b = f(1, n-1, nums, dp);
        
        return max(a,b);
    }
};

int main(){
    Solution newSol;
    vector<int> coins = {1,2,3};
    cout << newSol.rob(coins);

    return 0;
}

