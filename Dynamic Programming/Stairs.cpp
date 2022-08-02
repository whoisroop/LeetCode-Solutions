#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int climbS(int n, vector<int> &dp) {
        if(n==0)    return 1;   //Passed Case   Starting From N You Reached 0th Stair
        if(n<0)     return 0;   //Failed Case
        
        if(dp[n] != -1){
            return dp[n];
        }
        
        else{
            int a = climbS(n-1, dp);
            int b = climbS(n-2, dp);
            return a+b;
        }      
        
    }
    
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return climbS(n, dp);
    }
};