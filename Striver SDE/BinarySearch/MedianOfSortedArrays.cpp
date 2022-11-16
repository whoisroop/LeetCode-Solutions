// LeetCode - 4. Median Of Two Sorted Arrays.
// Binary Search On Answer.
// Predict a value and check the elements lesser than the predicted value in the array using upper bound concept.
// Make sure the predicted value is the smallest one that satisfies the condition, makes sure that the element is actually present in the arrays.
// For Example: {1, 3, 5, 7, 9}
// The value 5 & 6 satisfies the elements lesser that the predicted value = N/2. However, 6 cannot be a candidate because it is not present in array.
// The smallest value that satisfies the condition that elements lesser than predicted value is N/2, is 5. 
// Because the flow will break at the element that is present in the array.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int> &A, vector<int> &B){
        int nA = A.size();
        int nB = B.size();
        if(nA == 0) return (nB%2!=0) ? B[nB/2] : (B[(nB/2)-1]+B[nB/2]) / 2.0 ;
        if(nB == 0) return (nA%2!=0) ? A[nA/2] : (A[(nA/2)-1]+A[nA/2]) / 2.0;
        
        int i = min(A[0],B[0]), j = max(A[nA-1], B[nB-1]);
        int midpoint;
        
        int elements = (nA+nB)/2;
        double median = 0;
        while(i<=j){
            midpoint = (i + (j-i)/2);
            //Elements smaller than the current midpoint.
            //The midpoint or predicted value is included, therefore subtract 1. {1 2 (3) 4 5} {1 5 7} Output of upperbound: 4 {1 2 (3) & 1}.
            int eLeft = (upper_bound(A.begin(), A.end(), midpoint) - A.begin()) + (upper_bound(B.begin(), B.end(), midpoint) - B.begin()) - 1;
            
            if(eLeft >= elements) j=midpoint-1;
            else i=midpoint+1;
        } median += i;
        
        if((nA+nB)%2 == 0){
            i = min(A[0],B[0]); j = max(A[nA-1], B[nB-1]);
            elements -= 1;
            
            while(i<=j){
                midpoint = (i + (j-i)/2);
                //Elements smaller than the current midpoint.
                int eLeft = (upper_bound(A.begin(), A.end(), midpoint) - A.begin()) + (upper_bound(B.begin(), B.end(), midpoint) - B.begin()) - 1;

                if(eLeft >= elements) j=midpoint-1;
                else i=midpoint+1;
            } median += i;
            
            median = median/2;
        }
        
        return median;
        
    }
};