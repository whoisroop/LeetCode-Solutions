// Solution Using DP
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int f(int n, vector<int> &dp){
        if(n<2) return n;
        
        if(dp[n]!=-1)   return dp[n];   //Step 2: Check if the subproblem is already solved.
        
        dp[n] = f(n-1, dp) + f(n-2, dp);    //Step 3: If not solved, solve and store the value.
        return dp[n];
    }
    
    int nthFibonacci(int n) {
        vector<int> subproblems(n+1, -1);   //Step 1: Create a storage for subproblems.
        //n+1 space: for n cases + 1 base case (0).
        
        return f(n, subproblems);
    }
};
