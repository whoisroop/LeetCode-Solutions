// LeetCode - 14. Longest Common Prefix.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &A) {
        int n = A.size();
        string compare = A[0];
        for(int i=1; i<n; i++){
            if(compare.size()==0) break;
            
            string aCompare = ""; //After Compare
            int m = min(compare.size(), A[i].size());
            
            for(int j=0; j<m; j++){
                if(compare[j] == A[i][j]) aCompare += compare[j];
                else break;
            }
            
            compare = aCompare;
        }
        
        return compare;
    }
};