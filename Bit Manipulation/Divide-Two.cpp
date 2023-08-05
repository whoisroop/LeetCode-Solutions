// Problem - Tug Of War
// Link - https://www.codingninjas.com/studio/problems/tug-of-war_985253?leftPanelTab=0
// Description - Divide the values into two subsets of equal size (if odd (N-1/2) & (N+1/2)) such that the difference of subset sum is minimum.
// Approach - 

// Bitset: POWER SET
// As all the items are selected and divided into either group X or Y, approach the problem using power set.
// Iterate through all the possible configurations & check if the elements selected matches the condition of equal partitioning.
// Check if the item is selected, add the item to group X, calculate sum of group Y = Total - group X.
// Store the minimum difference.

// Time - O(2^N)
// Space - O(1)

#include<bits/stdc++.h>
using namespace std;

class Solution{
private:

public:
    int tugOfWar(vector<int> &A, int N){
        int cset = N/2;
        int totalsum = 0; for(int i=0; i<N; i++) totalsum += A[i];

        int minV = INT32_MAX;
        long long int till = (1 << N);

        for(int i=0; i<till; i++){
            if(__builtin_popcount(i) == cset){
                int X = 0; int Y = 0;
                for(int j=0; j<N; j++) if((i & (1 << j)) != 0) X += A[j];
                Y = totalsum - X;

                int D = ((X-Y) > 0) ? (X-Y) : (Y-X);
                minV = min(minV, D);
            }
        }

        return minV;
    }
};

int main(){
    Solution solve;
    
    return 0;
}