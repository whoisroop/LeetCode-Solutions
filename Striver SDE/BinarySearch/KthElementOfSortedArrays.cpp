// GFG - Kth Element Of Sorted Arrays.
// Same concept as median of sorted arrays: Elements on left = K - 1.

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int kthElement(int A[], int B[], int nA, int nB, int k){
        int eLeft = k-1;    //Elements on left of answer.
        int i=0, j=INT32_MAX;
        int midpoint;
        
        while(i<=j){
            midpoint = (i + (j-i)/2);
            int elements = (upper_bound(A, A+nA, midpoint) - A) + (upper_bound(B, B+nB, midpoint) - B) - 1; //Elements on left of midpoint.
            
            if(elements >= eLeft) j=midpoint-1; //Make sure it's the smallest to satisfy the condition.
            else i=midpoint+1;
        }
        
        int element = i;
        return element;
    }
};