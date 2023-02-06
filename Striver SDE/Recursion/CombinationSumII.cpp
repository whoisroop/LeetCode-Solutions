// LeetCode - 40. Combination Sum II
// Description - 
// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.
// Each number in candidates may only be used once in the combination.
// Note: The solution set must not contain duplicate combinations.

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
            combination(index - 1, target - A[index], A, subset, solution);
            subset.pop_back();
        }

        // Not Take:
        int i = index;
        while((i > 0) && (A[i] == A[i-1])) i -= 1;
        combination(i - 1, target, A, subset, solution);

        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& A, int target) {
        int n = A.size();
        sort(A.begin(), A.end());

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