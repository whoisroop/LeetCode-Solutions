// LeetCode - 26. Remove Duplicate From Sorted Array.

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int> &A) {
        int n = A.size();
        int i=0, j=0;   //i: Where to store. j: Current element.
        
        while(j<n){
            if(j==0 || A[j]!=A[j-1]){
                A[i] = A[j];
                i++;
            }
            
            j++;
        }
        
        return i;
    }
};