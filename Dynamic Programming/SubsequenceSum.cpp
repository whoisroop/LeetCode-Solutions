#include<iostream>
#include<vector>
using namespace std;
int maxSum = 1000;

class Solution{
public:
    int isSum(vector<int> &nums, int sum){
        int n = nums.size()-1;  //Last Index
        vector<vector<int>> dp(n+1, vector<int>(maxSum, -1));   //Index & Target: Changing Variables
        return (findSum(n, sum, nums, dp));
    }
    
    int findSum(int i, int target, vector<int> &nums, vector<vector<int>> &dp){
        if(target==0)   return 1;
        if(i<0)    return 0;
        
        if(dp[i][target] != -1) return dp[i][target];

        int take = false;
        if(nums[i]<=target) take = findSum(i-1, (target-nums[i]), nums, dp);
        int notTake = findSum(i-1, target, nums, dp);
        return (dp[i][target] = (take||notTake));
    }

};

int main(){
    vector<int> array = {5,4,1,2};
    int sum = 9;
    Solution newSol;
    cout << newSol.isSum(array, sum);
    return 0;
}