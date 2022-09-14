//LeetCode - 494. Target Sum.
//You are given an integer array nums and an integer target.
//You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

//The question states that divide the given array into two subarrays one denoting the positive & negative such that taking the difference of sum of all elements in the subarrays will result to target. S1 - S2 = Target
//{1,2,3} Target = 2
//{1,3} - {2} || +1-2+3 

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    //Ways of forming subset with sum: Element can only be selected once per subset.
    //S1+S2=TotalSum & S1-S2=Target
    //S1 = (TotalSum+Target)/2.
    int find(int index, int target, vector<int> &array, vector<vector<int>> &dp){
        if(target==0) return 1;
        if(index<0) return 0;

        if(dp[index][target]!=-1)   return dp[index][target];
        int take=0;
        if(target>=array[index]) take = find(index-1, target-array[index], array, dp);
        int notTake = find(index-1, target, array, dp);

        return dp[index][target] = (take+notTake);
    }

    int totalWays(vector<int> &array, int value){
        sort(array.begin(), array.end(), greater<int>());   //Tackle Zeroes.
        int n = array.size();
        int sum=0;  for(const int &i: array) sum+=i;
        
        value = abs(value);
        if((sum+value)%2!=0 || (sum+value)<0) return 0;
        if(sum==0) return pow(2, n);
        int target = (sum+value)/2;

        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        return find(n-1, target, array, dp);
    }
};

int main(){
    vector<int> array = {0,0,0,0,0,0,0,0,1};
    int target = 1;
    Solution find;
    cout << find.totalWays(array, target);
    return 0;
}