// GFG - Minimum number of jumps.
// Description - Given an array of N integers A[] where each element represents the maximum length of the jump that can be made forward from that element. This means if A[i] = x, then we can jump any distance y such that y ≤ x.
// Find the minimum number of jumps to reach the end of the array (starting from the first element). If an element is 0, then you cannot move through that element.
// Note: Return -1 if you can't reach the end of the array.

// Example: 2 3 1 1 4
// Intital Range: 0,0
//  0  1 2 3 4  : INDEX
// [2] 3 1 1 4
// Farthest reachable index: 0 + A[0] = 2

// NEXT RANGE: 1, 2
// 2 [3 1] 1 4
// Farthest reachable index: max(1 + A[1], 2 + A[2]) = 5; All the indexes < 5 are also reachable, range: j + 1 to maxindex.

// NEXT RANGE: 3, 5
// The last index is reachable: Solution = Number of iterations.

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int minJumps(int A[], int N){
        // GREEDY:
        // 1D BFS: From current reachable indexes find the next set of index that you can jump to.
        // Continue until the end is reached:
        
        int counter = 0;
        int i=0, j=0;   // Initial jump range: 0 to 0
        //The moment N-1 is in range: Solution.
        while(j < N-1){ 
            if(i > j) return -1;
            
            int maxjump = 0;
            for(int index=i; index<=j; index++) maxjump = max(maxjump, (index + A[index]));
            
            i = j+1;
            j = maxjump;
            counter += 1;
        }
        
        return counter;
    }
};

int main(){
    Solution solve;
    
    return 0;
}