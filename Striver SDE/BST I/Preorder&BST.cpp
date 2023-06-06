// GFG: Preorder Traversal and BST.
// Description: Given an array A[] of size N consisting of distinct integers, write a program that returns 1 if given array can represent preorder traversal of a possible BST, else returns 0.
// Approach: 

// PREORDER: N L R ; (L : Elements < N) & (R : Elements > N)
// {10 6 4 5 7 8 9 12 11}
// 10 [6 4 5 7 8 9] [12 11]
// N        L          R

// RANGE : CONCEPT:
//                   10
//  L: [-INTMAX, 10]    R: [10, +INTMAX]

// STACK : [ [10, +] [-, 10] ]

// The next element in the preorder traversal, will be checked for the left range. N L R
// Stack Top: [-, 10] Next Element: 6
// 6 IN RANGE [-, 10]

//                   10
//          6                 R:[10, +]
// L:[-, 6]   R:[6, 10]

// STACK : [ [10, +] [6, 10] [-, 6] ]

// Maintain a stack, push the right range & then left range, as the left range of the current element will be evaluated for the next element in the preorder traversal.
// If the element is in the range of the left: Insert the element's right & left range and pop the current node, as the element is inserted onto the left of the current node.
// If not, pop the current node & you'll shift the range to the right of parent node, check for range, until found keep popping.

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int canRepresentBST(int A[], int N) {
        stack<pair<int, int>> stk;  //UPPER LIMIT, LOWER LIMIT
        stk.push({INT32_MIN, INT32_MAX});
        
        int index = 0;
        while(index < N && !stk.empty()){
            auto top = stk.top(); stk.pop();
            int nValue = A[index];
            int minV = top.first, maxV = top.second;
            
            if(nValue > minV && nValue < maxV){
                stk.push({nValue, maxV});
                stk.push({minV, nValue});
                
                index += 1;
            }
        }
        
        return (index == N);
    }

    //RECURSIVE:
    bool check(int i, int j, int A[]){
        if(i >= j) return true;
        
        int index = i+1;    //BreakPoint
        while(index <= j && A[index] < A[i]) index += 1;
        
        // CHECK:
        for(int x=index; x<=j; x++) if(A[x] <= A[i]) return false;
        
        bool LEFT = check(i+1, index-1, A);    //SubTree
        if(LEFT == false) return false;
        
        bool RIGHT = check(index, j, A);         //SubTree
        if(RIGHT == false) return false;
        
        return true;
    }
};

int main(){
    Solution solve;
    
    return 0;
}