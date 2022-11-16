// LeetCode - 33. Search In Rotated Array.

// A = {3, 4, 5, 6, 0, 1, 2}
// 3 4 5 6 | 0 1 2 3 4 5 6 : Pivot Index: 4, Last Element Index: 4 + SIZE - 1 = 10.
// 0 1 2 3   4 5 6 7 8 9 10 - Index
//           i           j
// Access the element in the array: Index = 10, Index For Array = Index%Size = 10%7 = 3.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int> &A, int value) {
        int n = A.size();
        int pivot = 0; //PivotIndex
        for(int i=0; i<n; i++){
            if(i!=0 && A[i] < A[i-1]){ pivot=i; break; }
        }
        
        int i=pivot, j=(pivot + (n-1));
        int midpoint;
        
        while(i<=j){
            midpoint = (i+j)/2;
            int index = (midpoint % n);
            
            if(A[index] == value) return index;
            
            if(A[index] > value) j = midpoint-1;
            else i = midpoint+1;
        }
        
        return -1;
    }
};