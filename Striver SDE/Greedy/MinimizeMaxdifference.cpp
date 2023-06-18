// GFG: Minimize Height I & II 
// Description: Either increase or decrease the element of the array by K. Return the minimum difference between minimum & maximum values afer the operation is performed once for each index.
// https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1

// Approach: 

// SORT THE ARRAY: A[LAST] - A[FIRST] = Current Difference (RANGE)
// Thought process:
// We know we need to increase the smaller elements by K & decrease the greater elements by K.
// The increment will be done till a specific index which will yeild the minimum range, if goes beyond the index, the element + K will go beyond the previous starting range. We're trying to compress the range.

// CURRENT RANGE: (7 - 1) = 6
// 1 1 2 3 7 ; K = 3
// + + + - -
// What we're doing is breaking the lines into two segments, the +++ & --, shift the +++ line to the right by K units & -- lines to the left by K units.
// How did we know this?
// Increment the value K till index (i = 0 to i = N-1) and find the new range, check whether the right end of the line segment +++ goes beyond the current right edge (7) & similarly is the left end of the line segment -- goes beyond the current left edge (1).

// 1 3 6 8; K = 2
// + + - -

// Two Lines Segments:
//    + + +     - - -
//  0 1 2 3 4 5 6 7 8 9 10
//        + + +
//          - - -
// After Shifting: RANGE (6 - 3) = 3

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int getMinDiff(int A[], int n, int K) {
        sort(A, A+n);
        
        int minR = (A[n-1] - A[0]);
        for(int i=0; i<n-1; i++){
            int xmax = max(A[i]+K, A[n-1]-K);
            int xmin = min(A[i+1]-K, A[0]+K);
            if(xmin < 0) continue;
            
            minR = min(minR, (xmax-xmin));
        }
        
        return minR;
    }
};

int main(){
    Solution solve;
    
    return 0;
}