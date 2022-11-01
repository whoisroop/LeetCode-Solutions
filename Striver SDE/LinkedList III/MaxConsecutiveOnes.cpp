// LeetCode - 485. Max Consecutive Ones.

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& A) {
        int n = A.size();
        int count = 0, maxi = 0;
        
        for(int i=0; i<n; i++){
            if(A[i]==1){ count++; maxi = max(maxi, count); }
            else count = 0;
        }
        
        return maxi;
    }
};