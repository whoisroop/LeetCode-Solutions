// GFG - Maximum Index.
// Description - Given an array arr[] of n positive integers. The task is to find the maximum of j - i subjected to the constraint of arr[i] <= arr[j].

// Approach - 

// The elements on the left-most & the right-most side satisfying the condition A[i] <= A[j] will contribute to the solution.
// The problem can be solved using two pointers approach, but how do we know that we need to search to the right-most of the current index j?
// Calculate a suffix maximum which stores the maximum value from [index ... N-1], so that when the index i & j are on the elements such that A[i] <= A[j], check if there exists an element greater than A[i] on the right so that incrementing the second pointer will increase the window size.
// If not, increment i index and continue to do so and keep track of max window size.

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int maxIndexDiff(int A[], int N) {
        vector<int> smax(N, 0); //Suffix Max
        smax[N-1] = A[N-1];
        for(int i=N-2; i>=0; i--) smax[i] = max(smax[i+1], A[i]);
        
        int i=0, j=0; int wsize = 0;
        while(j < N){
            if(smax[j] >= A[i]){ wsize = max(wsize, (j-i)); j += 1; }
            else i += 1;
        }
        
        return wsize;
    }

};

int main(){
    Solution solve;
    
    return 0;
}