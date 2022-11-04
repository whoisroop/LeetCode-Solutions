// LeetCode - 503. Next Greater Element II.

// Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.
// The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.

#include<bits/stdc++.h>
using namespace std;

// Approach:
// So as we do not have any candidate for comparision with ith element when we traverse from i=0 to i=n-1 : Here we'll traverse the array in reverse and store the candidates suitable for next greater elements.
// As we traverse from the end the ith element will be compared with (i+1, i+2... n-1) elements. (BRUTE)
// Use stack to store the candidates: 
// If the current element is greater then the top of the stack (Most Recent Entry (i+1)), pop or remove it from the stack as it can not be a candidate for (0 1... i-1) as the ith element is greater than that (it'll replace it as a candidate).
// Pop the stack until the element at the top is greater than the ith element, which is the next greater for ith.
// Store the stack top element as the next greater element for the ith element.
// Push the current element into the stack as a candidate.

// For circular array: Run the loop twice, preserving the stack from the first iteration.
// For Array (1 2 3 4) : 1 2 3 4 1 2 3 4 The circular array is equivalent to two linear arrays.

class Solution {
public:
    vector<int> nextGreaterElements(vector<int> &A) {
        int n = A.size();
        vector<int> nge(n, -1);
        stack<int> stk;
        
        for(int i=(2*n-1); i>=0; i--){
            int index = (i%n);
            while(!stk.empty() && stk.top() <= A[index]) stk.pop(); //Remove candidates.
            
            if(!stk.empty()) nge[index] = stk.top();
            else nge[index] = -1;
            
            stk.push(A[index]);
        }
        
        return nge;
    }
};