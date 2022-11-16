// LeetCode - 540. Find Single Element In Sorted Array.

// You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.
// Return the single element that appears only once.
// Your solution must run in O(log n) time and O(1) space.

// APPROACH:
//The idea is to decrease the search space, where the partitioning will be done on the basis of left part & right part of the single element to be found:
//The left part will contain first occurrence on even index & second one on odd index.
//However after the index of the single element the order changes.
//Find the first element after the left part: Single Element (UpperBound Similarity).

//Check if the midpoint lies in the left part if not i = midpoint+1.
//If index is even check (compare) the next element. 
//If index is odd check (compare) the previous element. 
//EvenNumber XOR 1 = Next Odd Number
//OddNumber XOR 1 = Previous Even Number 

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    
    int singleNonDuplicate(vector<int> &A){
        int n = A.size(); if(n == 1) return A[0];
        
        int i=0, j=(n-1);
        int midpoint;
        
        while(i<=j){
            midpoint = j + (i-j)/2;

            //If the middle point index: Even
            if(midpoint%2 == 0){
                if(midpoint!=(n-1) && A[midpoint] == A[midpoint+1]) i = midpoint+1;
                else j = midpoint-1;
            }
            else{
                if(midpoint!=0 && A[midpoint] == A[midpoint-1]) i = midpoint+1;
                else j = midpoint-1;
            }
        }
        
        return A[i];
    }

};
