// Problem - Four Sum.
// Link - https://practice.geeksforgeeks.org/problems/find-all-four-sum-numbers1732/1?page=3&sprint=a663236c31453b969852f9ea22507634&sortBy=submissions 
// Description - Find unique quadrule solutions.

// Approach:
// A + B + C + D = T
// A + B = T - (C + D)
// Select two elements C & D using looping & apply two pointers to find solution A + B = Reduced Target.
// To eliminate the repeating solution, Add condition when solution is found: 1 (2) 2 3 (3); Move to the last indexes (i++ j-- till same elements) - 1 2 (2) (3) 3, the repetition is removed, do the same when choosing C & D.

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<vector<int> > fourSum(vector<int> &A, int target) {
        sort(A.begin(), A.end());
        // A + B + C + D = Target
        // C + D = Target - (A + B)
        vector<vector<int>> solution;
        int N = A.size();
        for(int ia=0; ia<N; ia++){
            if(ia != 0 && A[ia] == A[ia-1]) continue;
            for(int ib=ia+1; ib<N; ib++){
                if(ib != ia+1 && A[ib] == A[ib-1]) continue;
                int value = target - (A[ia] + A[ib]);
                
                int ic=ib+1, id=N-1;
                while(ic < id){
                    int sum = A[ic] + A[id];
                    if(sum == value){
                        while(ic < id && A[ic] == A[ic+1]) ic += 1;     //TO REMOVE REPETITION
                        while(ic < id && A[id] == A[id-1]) id -= 1;     //TO REMOVE REPETITION
                        solution.push_back({A[ia], A[ib], A[ic], A[id]});
                        ic += 1; id -= 1;
                    }
                    else if(sum > value) id -= 1;
                    else ic += 1;
                }
            }
        }
        
        return solution;
    }
};

int main(){
    Solution solve;
    
    return 0;
}