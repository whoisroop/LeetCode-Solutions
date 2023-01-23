// LeetCode - 945. Minimum Increment to Make Array Unique.
// You are given an integer array A. In one move, you can pick an index i where 0 <= i < A.length and increment A[i] by 1.
// Return the minimum number of moves to make every value in A unique.

// How to count the minimum increments, to make every element unique?
// 1 1 2 2 3 7
// The step size of converting 1 --> 4 is similar if we break down: 1 --> 2 --> 3 --> 4.
// Here, we'll check that the current element must be greater then previous, if not some correction is needed.
// 1 (1) 2 2 3 7
// Here, A[i] <= A[i-1]:
// The element at A[i] should've been A[i-1] + 1: The increment needed is ((A[i-1] + 1) - A[i]).
// After incrementing, modify increment variable and the value at A[i].
// 1 2 (3) 2 3 7
// 1 2 3 (2) 3 7
// Here, A[i] <= A[i-1]:
// The element should've been A[i-1] + 1 that is (3 + 1 = 4), the increment needed is (4 - 2 = 2).
// Total Increment = 1 + 2 || Array = 1 2 3 4 3 7
// 1 2 3 4 (3) 7
// Here, A[i] <= A[i-1]:
// 1 2 3 4 5 (7)
// END:
// TOTAL INCREMENT: 1 + 2 + 3 = 6
// FINAL ARRAY: 1 2 3 4 5 7

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minIncrementForUnique(vector<int> &A) {
        int n = A.size();
        if(n == 1) return 0;

        sort(A.begin(), A.end());

        int increment = 0;
        for(int i = 1; i<n; i++){
            if(A[i] <= A[i-1]){
                increment += ((A[i-1] + 1) - A[i]);
                A[i] = (A[i-1] + 1);
            }
        }

        return increment;
    }
};