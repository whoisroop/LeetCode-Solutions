// Problem - Minimum Number Of Jumps 
// Description - https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1?page=1&curated[]=1&sortBy=submissions

// Approach:
// Create a range till where you can reach in the current iteration, and then move from current + 1 to next range & determine new range i.e. max & count the number of iterations needed.
// {(2),1,1,2,1} : 1st iteration the range is <= 0, the new range is : position 0 + jump 2 = 2
// {2, (1, 1), 2, 1} : 2nd iteration the range is [0+1, 2], the new max range is : position 2 + jump 1 = 3
// {2, 1, 1, (2), 1} : 3rd iteration the range is [2+1, 3], the new max range is : position 3 + jump 2 = 5 >= N, the end is reached.

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

// Problem - Water the plants
// Link - https://practice.geeksforgeeks.org/problems/410d51d667ab93f2219b15126f001f32e8bb029e/0

// The problem is just the same as minimum number of jumps, the sprinkler can spray for the range i - A[i] & i + A[i];
// Decompose the problem, generate an array with the range, it just signifies if the current spinkler at i-A[i] is turned on, it sprays till i+A[i].
// Jumps from (current, next) or (i - A[i], i + A[i]).

class Solution{
    public:
    int min_sprinklers(int sprinkler[], int N){
        vector<vector<int>> A;
        
        for(int i=0; i<N; i++){
            if(sprinkler[i] != -1) A.push_back({max(0, i-sprinkler[i]), min(N, i+sprinkler[i])});
        }
        
        sort(A.begin(), A.end());
        
        int maxrange = 0;
        int index = 0;
        int counter = 0;
        while(index < A.size()){
            int nrange = -1;
            while(index < A.size() && A[index][0] <= maxrange) { nrange = max(nrange, A[index][1]); index += 1; }
            if(nrange < maxrange) return -1;
            // cout << maxrange << " " << nrange << endl;
            maxrange = nrange + 1;
            
            counter += 1;
            if(maxrange >= N) return counter;
        }
        
        return -1;
    }
};

int main(){
    Solution solve;
    
    return 0;
}