#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int recursion(int n, vector<int> &cost, vector<int> &dp){
        if(n<2)    return cost[n];
        
        if(dp[n]!=-1)   return dp[n];
        
        else{
            int l = recursion(n-1, cost, dp);
            int r = recursion(n-2, cost, dp);
            
            dp[n] = min(l,r) + cost[n];
            return dp[n];
        }
        
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1, -1);
        int nthStep = cost.size();
        cost.push_back(0);  //Cost for nth step is set to zero. Start from here.
//Or alernate: return min(recursion(nthStep-1, cost, dp), recursion(nthStep-2, cost, dp))
//Find the least value to reach n-1 or n-2 step as the last jump doesn't require energy
        return recursion(nthStep, cost, dp);
    }
};