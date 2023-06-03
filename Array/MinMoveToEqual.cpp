// GFG: Optimal Array.
// Description - You are given a sorted array a of length n. For each i(0<=i<=n-1), you have to make all the elements of the array from index 0 till i equal, using minimum number of operations. In one operation you either increase or decrease the array element by 1.
// You have to return a list which contains the minimum number of operations for each i, to accomplish the above task.

// APPROACH: Making elements equal to median takes the minimum operations!
// For every element, make the elements equal to the median and calculate the steps.
// To optimize time complexity to O(N):
// PROPERTY: MEDIAN
// Making elements equal to median takes the minimum operations!
// Shifting of median from current to next on the right, doesn't change the minsteps of the elements required to change element to the median when a new element in added.
// EXAMPLE: 1 (2) 4 5 --> 1 2 (4) 5 | 7
// The number of steps required to make elements 1, 4, 5 to median 2 is equal to 1, 2, 5 to median 4: CONSECUTIVE MEDIANS.
// --- --------         A
//     -----            B
// *  x     *  *
// 1--2--3--4--5--6--7
// *  *     x  *
// --------- --         C
//     -----            D
//           ........ (New Element)

// STEPS: 
// MEDIAN 2 : A + B
// MEDIAN 4 : C + D
// From the above diagram: A+B = C+D, The number of operations doesn't change when the medians are shifted to consecutive median by adding an element.

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> optimalArray(int N,vector<int> &A){
        vector<int> minmove(N, 0);
        for(int i=1; i<N; i++){
            minmove[i] = minmove[i-1] + (A[i] - A[i/2]);
        }
        
        return minmove;
    }
};

int main(){
    Solution solve;
    
    return 0;
}