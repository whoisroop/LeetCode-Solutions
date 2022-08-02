//Longest Increasing Subsequence: REFER
// Given an integer array nums, return the number of longest increasing subsequences.
// Notice that the sequence has to be strictly increasing.
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size()-1;
        vector<int> dp(n+1, 1);
        vector<int> count(n+1, 1);  //To store count of ways the same length subsequence is formed.
        int maxi = 1;
        for(int i=1; i<=n; i++){
            for(int pi=0; pi<i; pi++){
                if((nums[i]>nums[pi]) && (dp[pi]+1>dp[i])){
                    dp[i] = dp[pi]+1;
                    maxi = max(maxi, dp[i]);
                    count[i] = count[pi];   //Number of ways [i] = Number Of ways [pi]
                }
                else if((nums[i]>nums[pi]) && (dp[pi]+1 == dp[i])){
                    count[i] += count[pi];  //If same length is formed again. Increase the count.
                }
            }
        }
        
        int total=0;
        for(int i=0; i<=n; i++){
            if(dp[i]==maxi) total+=count[i];
        }
        return total;
    }
};