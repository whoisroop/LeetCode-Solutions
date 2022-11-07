// GFG - Celebrity Problem.
// A celebrity is a person who is known to all but does not know anyone at a party. If you go to a party of N people, find if there is a celebrity in the party or not.
// A square NxN matrix M[][] is used to represent people at the party such that if an element of row i and column j  is set to 1 it means ith person knows jth person. Here M[i][i] will always be 0.

// Approach: Method Of Elimination Using Stack (PEPCODING YT)
// Push all the candidates for celebrity into the stack.
// Pop the top two elements & compare : Add one of the two potential candidate back.
// Continue till one element is left.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int celebrity(vector<vector<int>> &A) {
        int n = A.size();

        // Using method of elimination:
        stack<int> stk;
        for(int i=0; i<n; i++) stk.push(i);
        
        while(stk.size()!=1){
            int pA = stk.top(); stk.pop();
            int pB = stk.top(); stk.pop();
            
            if(A[pA][pB] == 1) stk.push(pB);    //If pA knows pB : pA is not the celebrity.
            else stk.push(pA);  //If pA doesn't know pB : pB is not the celebrity.
        }
        
        int index = stk.top(); //Index of potential candidate for celebrity.
        
        for(int i=0; i<n; i++){
            if(i==index) continue;
            if(A[i][index] != 1 || A[index][i] != 0) return -1;
        }
        
        return index;
    }
};