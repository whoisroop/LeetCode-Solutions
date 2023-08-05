// Problem - Controlled Selection, generate unique subsets. 
// Link - https://practice.geeksforgeeks.org/problems/subset-sum-ii/0

#include<bits/stdc++.h>
using namespace std;

// Controlled Selection Problem:
class Solution {
private:
    void formset(int index, vector<int> &subset, vector<int> &A, vector<vector<int>> &solution){
        int N = A.size();
        if(index == N){ solution.push_back(subset); return; }
        
        for(int ni=index; ni<N; ni++){
            // Take:
            if(ni == index || A[ni] != A[ni-1]){
                subset.push_back(A[ni]);
                formset(ni+1, subset, A, solution);
                subset.pop_back();
            }
        }
        
        // END THE SUBSET:
        formset(N, subset, A, solution);
        
        return;
    }
    
public:
    vector<vector<int>> printUniqueSubsets(vector<int> &A) {
        sort(A.begin(), A.end());
        
        vector<vector<int>> solution;
        vector<int> subset;
        formset(0, subset, A, solution);
        return solution;
    }
};

int main(){
    Solution solve;
    
    return 0;
}