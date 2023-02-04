// LeetCode - 31. Next Permutation
// Description - 
// Algorithm:
// Think of how we permute:
// 1 2 3 --> 1 3 2 --> 2 1 3 --> 2 3 1 --> 3 1 2 --> 3 2 1
// For example: 1 (3 2) As the last two digits are the last possible permutation of [2 , 3] i.e. (3,2) we need to consider the element before it to make the next permutation. But which one should we replace it with?
// To find the just greater number, we need to increase the weight of the digit at the breaking point (1) as minimum as possible. 
// So swap the element 1 with the element that is just greater than 1. In this case i.e. 2:
// 1 3 2 --> 2 3 1
// Now the weight at the index zero is increased by the minimum possible value.
// Now all the other element on the right are in increasing order from right to left. We need to minimize their weight as well.
// Therefore, reverse the elements from (index + 1 , N - 1).

// 1 3 2 : 1 x 10^2 + 3 x 10^1 + 2 x 10^0
// 2 3 1 : 2 x 10^2 + 3 x 10^1 + 1 x 10^0

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& A) {
        int n = A.size();
        int index = n - 1;

        // First decreasing element from right:
        while(index > 0 && A[index - 1] >= A[index]) index -= 1;
        index -= 1;

        // Reverse and sort are equivalent.
        if(index < 0){ reverse(A.begin(), A.end());} //No Next Permutation. 4 3 2 1.
        else{
            int j = index; int minvalue = INT32_MAX;

            // Find the just greater element to the right of index:
            // Swap with right most, as it is reversed not sorted. Duplicates.
            for(int i = n - 1; i > index; i--){
                if(A[i] > A[index] && A[i] < minvalue){ minvalue = min(minvalue, A[i]); j = i; }
            }

            swap(A[index], A[j]);
            reverse(A.begin() + (index + 1), A.end());
        }
    }
};

int main(){
    Solution solve;

    return 0;
}