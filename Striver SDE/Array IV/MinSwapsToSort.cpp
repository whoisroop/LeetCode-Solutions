// GFG - Find Minimum No. Of Swaps To Sort An Array.

// Approach:
// Create a copy of the array A & sort it.
// Store the index of elements of A where it is supposed to be, in order to be sorted in a map. Using sorted array for reference.
// Traverse through the array A & if the current element at ia is supposed to be at ib, check where the the element ib is supposed to be and so on until a visited state is reached.

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