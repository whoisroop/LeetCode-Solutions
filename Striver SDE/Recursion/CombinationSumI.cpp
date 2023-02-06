// LeetCode - 39. Combination Sum
// Description - 
// Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.
// The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void combination(int index, int target, vector<int> &A, vector<int> &subset, vector<vector<int>> &solution){
        if(target == 0) { solution.push_back(subset); return; }
        if(index < 0) { return; }

        // Take:
        if(target >= A[index]){
            subset.push_back(A[index]);
            combination(index, target - A[index], A, subset, solution);
            subset.pop_back();
        }

        // Not Take:
        combination(index - 1, target, A, subset, solution);

        return;
    }
    vector<vector<int>> combinationSum(vector<int> & A, int target) {
        int n = A.size();
        vector<int> subset;
        vector<vector<int>> solution;

        combination(n - 1, target, A, subset, solution);

        return solution;
    }
};

int main(){
    Solution solve;
    
    return 0;
}