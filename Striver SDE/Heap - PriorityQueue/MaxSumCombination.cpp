// GFG - Max Sum Combination.
// Given two integer array A and B of size N each.
// A sum combination is made by adding one element from array A and another element of array B.
// Return the maximum K valid distinct sum combinations from all the possible sum combinations.
// Note : Output array must be sorted in non-increasing order.

// BRUTE FORCE:
// Sort Both Arrays.
// A = {1,2,3,4} B = {2,3,5,6} (ia = N-1, ib = N-1)
// Add the current index sum to the vector & then move either ia or ib and repeat the process for (ia, ib-1) & (ia-1, ib).

// Here, as we prioritize the branch that yields the solution using priority queue and stop when the solution is achieved.
// The max sums will consist of max values from each arrays.

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        
        vector<int> solution;
        priority_queue<pair<int, pair<int, int>>> pq; // <SUM, <Index, Index>>
        set<pair<int, int>> visited;    // To store the visited states.
        
        int i=N-1, j=N-1;
        pq.push({A[i]+B[j], {i, j}});
        while(K>0){
            i = pq.top().second.first;
            j = pq.top().second.second;
            
            if(visited.find({i,j}) == visited.end()){   //If State Is Not Visited
                solution.push_back(pq.top().first); 
                K--; visited.insert({i,j});
                
                if(i-1 >= 0) pq.push({(A[i-1] + B[j]), {i-1, j}});
                if(j-1 >= 0) pq.push({(A[i] + B[j-1]), {i, j-1}});
            }
            
            pq.pop(); 
        }
        
        return solution;
    }
};