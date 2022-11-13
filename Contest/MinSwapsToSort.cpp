// GFG - Find Minimum No. Of Swaps To Sort An Array.

// Approach: Array: A & B = Sort(A)
// Assume creating a graph with nodes as elements of A & edges pointing to the other node (index) where it belongs in the sorted array (B). Store the index it belongs to using map. MAP[value] = Index.
// A = 3 2 1 || B = 1 2 3
// 1. Value 3 belongs to index 2 in sorted case.
// 2. The value at index 2 belongs to index 0. Where we started from, hence we reached a visited state.
// The number of swaps required to bring the value 1 & 3 in place are: EDGES - 1.
// Similarly traverse through A and perform the algorithm for each index of A if not already visited state (index).

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int> &A){
	    int n = A.size();
	    vector<int> B = A;
	    sort(B.begin(), B.end());
	    
	    unordered_map<int, int> imap; //Index Of Value A[i] In The Sorted Array B.
	    for(int i=0; i<n; i++) imap[B[i]] = i;
	    
	   // Find Cycles
	   vector<bool> visited(n, false); //Visited For A[]
	   int swaps = 0;
	   for(int i=0; i<n; i++){
	       if(imap[A[i]] == i || visited[i] == 1) continue;
	       
	       int cycle = 0;
	       int ni = i; //Next Index
	       while(visited[ni] != true){
	           visited[ni] = true;
	           cycle+=1;
	           ni = imap[A[ni]];
	       }
	       
	       swaps+=(cycle-1);
	   }
	   
	   return swaps;
	}
};