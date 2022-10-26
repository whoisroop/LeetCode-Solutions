// LeetCode - 560. Subarray Sum Equal K.
// Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
// A subarray is a contiguous non-empty sequence of elements within an array.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int> &A, int k) {
        int n = A.size();
        
        unordered_map<int, int> fmap;   //To map prefix sum to its occurences.
        int sum=0; int counter=0;
        
        fmap[0] = 1;    //Count of occurences of subarray sum zero.
        for(int i=0; i<n; i++){
            sum += A[i];
            
            //After obtaining the prefix sum for current index, B: Check if any of the previous prefix sum A : B - A = K --> B - K = A
            //Here, B = SUM & FIND A: SUM - K
            if(fmap.find(sum - k) != fmap.end()) counter += fmap[sum-k];
            
            fmap[sum]++;    //At the bottom as K can be 0.
        }
        
        return counter;
    }
};