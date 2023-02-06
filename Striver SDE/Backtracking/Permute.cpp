// LeetCode - 46. Permutations
// Description - 
// Given an array A of distinct integers, return all the possible permutations. You can return the answer in any order.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void permute(int index, vector<int> &A, vector<vector<int>> &solution){
        if(index < 0){ solution.push_back(A); return; }

        for(int i=0; i<=index; i++){
            swap(A[index], A[i]);
            permute(index - 1, A, solution);
            swap(A[index], A[i]);
        }

        return;
    }

    vector<vector<int>> permutation(vector<int> &A) {
        int n = A.size();
        vector<vector<int>> solution;
        
        permute(n - 1, A, solution);

        return solution;
    }
};

int main(){
    Solution find;

    return 0;
}