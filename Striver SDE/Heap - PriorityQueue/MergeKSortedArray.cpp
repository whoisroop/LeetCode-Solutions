// GFG - Merge K Sorted Array.
// Given K sorted arrays arranged in the form of a matrix of size K*K. The task is to merge them into one sorted array.

// INPUT:
// K = 3
// A[][] = {{1,2,3},{4,5,6},{7,8,9}}
// Output: 1 2 3 4 5 6 7 8 9

// Explanation:Above test case has 3 sorted
// Arrays of size 3, 3, 3
// A[][] = [
// [1, 2, 3],
// [4, 5, 6], 
// [7, 8, 9]
// ]
// The merged list will be 
// [1, 2, 3, 4, 5, 6, 7, 8, 9].

#include<bits/stdc++.h>
using namespace std;

// COMPARATOR FOR PRIORITY QUEUE:
struct compare{
  bool operator()(pair<int, pair<int, int>> &A, pair<int, pair<int, int>> &B){
     return A.first > B.first;
  }
};

// Same concept as merging two sorted arrays.
// Use max heap to keep track of the indexes.

class Solution
{
    public:
    vector<int> mergeKArrays(vector<vector<int>> A, int n){
        // COMPARATOR: greater<pair<int, pair<int, int>>>
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, compare> minheap;   //<Value, <I, J>>
        vector<int> sorted;
        
        for(int i=0; i<n; i++) minheap.push({A[i][0], {i, 0}});
        
        while(!minheap.empty()){
            int i = minheap.top().second.first;
            int j = minheap.top().second.second;
            int value = minheap.top().first;
            
            minheap.pop();
            
            if(i<n && j<n){
                sorted.push_back(value);
                if((j+1)<n) minheap.push({A[i][j+1], {i, j+1}});
            }
        }
        
        return sorted;
    }
};