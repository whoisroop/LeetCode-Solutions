// You are given an integer array nums and an integer target.

// You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

// For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
// Return the number of different expressions that you can build, which evaluates to target.

//DIVIDED INTO TWO SUBSETS WITH S1-S2 = Target
#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    //Number Of Subsets With Given Sum
    int f(int index, int target, vector<int> array, vector<vector<int>> &dp){
        if(index==0){
            if(array[0] == 0 && target == 0)   return 2;
            if(target == array[0] || target == 0)  return 1;
            else    return 0;
        }
        if(dp[index][target]!=-1)   return dp[index][target];

        int notTake = f(index-1, target, array, dp);
        int take = 0;
        if(array[index]<=target)    take = f(index-1, target-array[index], array, dp);
        return dp[index][target] = (take + notTake);
    }

    int subsetSum(vector<int> array, int sum){
        int n = array.size()-1;
        vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
        return f(n, sum, array, dp);
    }

    //Tabulated & Optimized

    int subsetSumOPT(vector<int> array, int sum){
        int n = array.size()-1;
        // vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));
        vector<int> curr(sum+1, 0), prev(sum+1, 0);
        //Base Case
        prev[0]=1;
        if(array[0]==0)    prev[0]=2;
        for(int target=1; target<=sum; target++){
            if(target == array[0])  prev[target]=1;
        }

        for(int index=1; index<=n; index++){
            for(int target=0; target<=sum; target++){
                int notTake = prev[target];
                int take = 0;
                if(array[index]<=target)    take = prev[target-array[index]];
                curr[target] = (take + notTake);
            }
            prev = curr;
        }

        return prev[sum];
    }

    //Subsets with given difference.
    int subsetDiff(vector<int> array, int difference){
        int n = array.size()-1;
        int totalSum = 0;
        for(int i: array)   totalSum += i;

        if((difference+totalSum)%2!=0 || (difference+totalSum<0))  return 0;
        int ways = subsetSum(array, (difference+totalSum)/2);
        return ways;
    }

};

int main(){
    vector<int> array = {0,0,1};

    Solution newSol;
    cout << newSol.subsetSumOPT(array, 1);
    return 0;
}