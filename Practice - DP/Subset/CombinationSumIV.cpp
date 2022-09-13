//LeetCode - 377. Combination Sum IV
//Given an array of distinct integers nums and a target integer target, return the number of possible combinations that add up to target.
//Example:
//Input: nums = [1,2,3], target = 4
// Output: 7
// Explanation:
// The possible combination ways are:
// (1, 1, 1, 1) (1, 1, 2) (1, 2, 1) (2, 1, 1) (1, 3) (3, 1) (2, 2)
// Note that different sequences are counted as different combinations.

// The problem is exactly similar to coin change II as we need to find the ways we can yeild a subset sum of target. 
//However, the repetition is allowed (order counts) i.e. (1,2) & (2,1) are valid subsets.
//So when taking the decision if an element is selected to be a part of the subset "TAKE" then when calling the function instead of for the current index, call it for the starting index.
//int take = find(index, target-array[index]) -->>> int take = find(lastIndex, array[index]).
//Again start the take notTake from the starting index.
//Covers all the permutations & when not take case is executed skip the current index to next index.

#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    int find(int index, int target, int li, vector<int> &array, vector<vector<int>> &dp){
        if(target==0) return 1;
        if(index<0) return 0;

        if(dp[index][target]!=-1)   return dp[index][target];

        int take=0;
        if(array[index]<=target) take = find(li, target-array[index], li, array, dp);
        int notTake = find(index-1, target, li, array, dp);

        return dp[index][target] = (take+notTake);
    }

    int combinations(vector<int> &array, int target){
        int n = array.size();
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        return find(n-1, target, n-1, array, dp);
    }

    //Simple Recursive Solution - TLE
    //int findTarget(int sum, int target, int li, vector<int> &array){
    //     if(sum==target) return 1;

    //     int count=0;
    //     for(int i=0; i<=li; i++){
    //         if((sum+array[i])<=target){
    //             count += findTarget(sum+array[i], target, li, array);
    //         }
    //     }

    //     return count;
    // }
};

int main(){
    vector<int> array = {1,2,3};
    Solution find;
    cout << find.combinations(array, 4);
    return 0;
}