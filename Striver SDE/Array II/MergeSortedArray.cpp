// LeetCode - 88. Merge Sorted Array.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int ia=(m-1), ib=(n-1); 
        int i=(m+n-1);
        
        while(ia>=0 && ib>=0){
            if(A[ia]>=B[ib]){
                A[i] = A[ia];
                ia--; i--;
            }
            else{
                A[i] = B[ib];
                ib--; i--;
            }
        }
        
        if(ia>=0 || ib>=0){
            if(ia<0 && ib>=0){
                while(ib>=0){
                    A[i] = B[ib];
                    ib--; i--;
                }
            }
            if(ib<0 && ia>=0){
                while(ia>=0){
                    A[i] = A[ia];
                    ia--; i--;
                }
            }
        }
        
        return;
    }
};