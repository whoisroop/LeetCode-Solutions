// GFG: There are N piles of coins each containing  Ai (1<=i<=N) coins. Find the minimum number of coins to be removed such that the absolute difference of coins in any two piles is at most K.
// Note: You can also remove a pile by removing all the coins of that pile.

// Description: https://practice.geeksforgeeks.org/problems/coin-piles5152/1
// Approach: 
// The inital approach would be to sort the array & compare the last elements with the first & adjust the coins by removing them from the last pile index j.
// However, we can also remove a piles by removing all the elements, that would be the first pile.
// Now, how to decide when to discard a pile & when to remove coins?
// The piles to be discarded should be discarded first, otherwise the solutions wouldn't be optimal.
// So, use a loop and discard the piles before the current loop index.
// Let the pile start at index & all the previous piles are discarded, the total coins in the discarded : SUM of piles [0 ... index - 1] can be computed using prefix sum.
// The elements in the range : A[index] to A[index] + K do not need the change of coins, as the max difference of K is allowed.
// Find the breakpoint & make them all equal to A[index] + K and add the coins removed from the pile.
// For the elements after the breakpoint: X Y Z - Coins Removed: (X - (A[index] + K)) + (Y - (A[index] + K)) + (Z - (A[index] + K)) = (X + Y + Z) - (N - BREAKPOINT) * (A[index] + K)
// The breakpoint can be calculated using binary search approach.

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minSteps(int given[], int N, int K) {
        vector<int> A(given, given+N);
        sort(A.begin(), A.end());
        
        vector<int> psum(N+1, 0);
        for(int i=1; i<=N; i++) psum[i] = psum[i-1] + A[i-1];
        // Prefix Sum till index: psum[index+1]
        
        // We can discard the first pile or remove the elements from the last:
        // Let the pile begin from index position i ; all the piles before are discarded.
        
        int total = INT32_MAX;
        for(int start = 0; start < N; start++){
            int coins = psum[start];    // The piles before given index are discarded.
            
            int index = (upper_bound(A.begin(), A.end(), A[start] + K) - A.begin());
            coins += (psum[N] - psum[index]) - (N - index) * (A[start] + K);
            
            total = min(total, coins);
        }
        
        return total;
    }
};

int main(){
    Solution solve;
    
    return 0;
}