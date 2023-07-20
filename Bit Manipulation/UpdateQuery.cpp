// GFG - Update Query.
// Link - https://practice.geeksforgeeks.org/problems/a6528c893d4ab645ec6e0690c7982748385099c8/1
// Description - 
// You are given an array of n elements, initially all a[i] = 0. Q queries need to be performed. Each query contains three integers l, r, and x  and you need to change all a[i] to (a[i] | x) for all l ≤ i ≤ r.

// Return the array after executing Q queries.

// Approach:
// When the query update is addition from range L to R indexes:
// We create an array containing zeros, add the value x to A[L] & subtract it from A[R+1];
// The net effect is the element is added for the range L to R, A[i] += A[i - 1] - For the current array.
// If there is another one with elements: given[i] += A[i]

// The OR operation is somewhat addition in binary.
// The single or multiple counts of ones at a position makes the bit set.
// For range L to R:
// We can store the bits for every index which will be used to OR onwards:
// Declare vector<vector<int>> A(N+1, vector<int>(32, 0));
// For OR : RANGE L to R ; Value: X
// Find the set bits and increase the count of that bit in A[L] & decrease the count of that bit at A[R+1]
// So when the value X goes out of range index > R: the counter will be decreased, preserving the other OR values in the range.
// To convert the decimal bit count value to integer: if(A[i][j] > 0) The jth bit is set.
// Count denotes the number of values OR'ed in the range, so that removing one value preserves the others. 

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> updateQuery(int N, int Q, vector<vector<int>> &INPUT){
        // Or is basically add operation.
        
        vector<vector<int>> A(N+1, vector<int>(32, 0));
        for(int i=0; i<Q; i++){
            int L = INPUT[i][0] - 1;
            int R = INPUT[i][1] - 1;
            int value = INPUT[i][2];
            
            for(int j=0; j<32; j++){
                int mask = (1 << j);
                if((mask & value) != 0){ A[L][j] += 1; A[R+1][j] -= 1; }
            }
        }
        
        for(int i=1; i<N; i++) for(int j=0; j<32; j++) A[i][j] += A[i-1][j];
        
        // CONVERT TO VALUES: DECIMAL
        vector<int> output;
        for(int i=0; i<N; i++){
            int iv = 0;
            for(int j=0; j<32; j++){
                if(A[i][j] > 0) iv |= (1 << j);
            }
            
            output.push_back(iv);
        }
        
        return output;
    }
};

int main(){
    Solution solve;
    
    return 0;
}