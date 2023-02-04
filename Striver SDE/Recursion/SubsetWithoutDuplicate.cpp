// LeetCode - 90. Subsets II
// Description - 
// Given an integer array nums that may contain duplicates, return all possible 
// subsets (the power set).
// The solution set must not contain duplicate subsets. Return the solution in any order.

// If we choose not to take an element, we won't take any of its occurences. Skip all the similar elements.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void makeset(int index, vector<int> &A, vector<int> &subset, vector<vector<int>> &solution){
        if(index<0) { solution.push_back(subset); return; }

        // Not Take:
        int i = index;
        while((i > 0) && (A[i] == A[i - 1])) i -= 1;
        makeset(i - 1, A, subset, solution);

        // Take:
        subset.push_back(A[index]);
        makeset(index - 1, A, subset, solution);
        subset.pop_back();

        return;
    }

    vector<vector<int>> uniqueSubsets(vector<int>& A) {
        int n = A.size();
        sort(A.begin(), A.end());
        vector<int> subset;
        vector<vector<int>> solution;
        makeset(n - 1, A, subset, solution);

        return solution;
    }
};

int main(){
    Solution solve;
    
    return 0;
}