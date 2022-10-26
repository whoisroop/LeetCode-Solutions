// LeetCode - 523. Continuous Subarray Sum.
// Given an integer array nums and an integer k, return true if nums has a continuous subarray of size at least two whose elements sum up to a multiple of k, or false otherwise.

// How to approach:
// Whenever there's a question on subarray sum : PREFIX SUM
// Calculate the prefix sum, prefix[i] : Sum of first 'i' elements in the array.
// In order to find a subarray with sum as a multiple of K: SUBARRAY SUM % K = 0
// The SUBARRAY SUM can be obtained by using prefix sum : Sum of (j ... i) : Prefix[i] - Prefix[j-1]
// Let The Subarray Sum: B & A
// We Need To Find Subarray: (B-A) = D ; Where D%K == 0
// (B-A)%K = D%K = 0
// B%K - A%K = 0, Hence: B%K = A%K (Condition To Follow)
// Use a map to store the index of the (A%K) and whenever a match is found, compare the current index with previous index map[A%K] to check if they are atleast two indexes apart: (i - mpp[A%K]) > 1

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int> &A, int k) {
        int n = A.size(); if(n<2) return false;
        
        vector<int> prefix(n+1, 0); //Sum of (j ... i) : Prefix[i] - Prefix[j-1]
        for(int i=0; i<n; i++){
            prefix[i+1] = prefix[i] + A[i];
        }
        
        //Using: HashMap
        unordered_map<int, int> mpp;    //To map the modded value to its index.
        for(int i=0; i<=n; i++){
            int mod = prefix[i]%k;
            
            if(mpp.find(mod)!=mpp.end()){
                if((i - mpp[mod]) > 1) return true;
            }
            else mpp[mod] = i;
        }
        
        // for(auto i: mpp) cout << i.first << " - " << i.second << endl;
        
        //Using: Set
        // unordered_set<int> mset;
        // int pmod = 0;   //Previous MOD : The subarray should not be adjacent
        // for(int i=0; i<n; i++){            
        //     cout << "SUM: " << prefix[i+1] << " MOD: " << i%k << endl;
        //     if(mset.find(prefix[i+1] % k)!=mset.end()) {return true;}
            
        //     mset.insert(pmod);
        //     pmod = prefix[i+1] % k;
        // }

        return false;
    }
};