// Problem - Find all distinct subset (or subsequence) sums.
// Link - https://practice.geeksforgeeks.org/problems/find-all-distinct-subset-or-subsequence-sums4424/1
// Description - Given a set of integers, find all distinct sums that can be generated from the subsets of the given sets.

// Approach:
// 1 2 3
// {}
// 1: Add 1 to all the exisiting subsets, creating new subsets.
// {} | {1}
// 2: Add 2 to all the exisiting subsets, creating new subsets.
// {} {1} | {2} {1,2}
// 3: Add 3 to all the exisiting subsets, creating new subsets.
// {} {1} {2} {1,2} | {3} {1,3} {2,3} {1,2,3}

// BitSet << Value : Adds value to all the set position on the bitset, creating new subsets.
// Also preserve the existing subset sums, bitset = bitset | (bitset << A[i]);

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> DistinctSum(vector<int> A){
	    int N = A.size();
	    bitset<10001> bset;
	    
	    bset[0] = 1;
	    for(int i=0; i<N; i++) bset |= (bset << A[i]);
	    
	    vector<int> solution;
	    for(int i=0; i<10001; i++) if(bset[i] == 1) solution.push_back(i);
	    return solution;
	}
};

int main(){
    Solution solve;
    
    return 0;
}