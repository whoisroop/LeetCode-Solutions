// LeetCode - 994. Rotting Oranges.

// You are given an m x n grid where each cell can have one of three values:
// 0 representing an empty cell,
// 1 representing a fresh orange, or
// 2 representing a rotten orange.
// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

// Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

// Approach: 
// Use a queue data structure to store the initial rotten oranges coordinates.
// Pop all the coordinates of the rotten oranges & check for nearby fresh oranges: Add the newly rotten into the queue.
// Continue till the queue is empty.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        
        // If no oranges: Edge case -
        bool noOrange = true;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2) q.push({i,j}); //If rotten push into the stack.
                if(grid[i][j] != 0) noOrange = false;
            }
        }
        
        if(noOrange) return 0;
        
        int minute = -1;
        while(!q.empty()){
            int size = q.size();
            
            for(int count=0; count<size; count++){
                // pair<int, int> ij = q.top();
                int i = q.front().first;
                int j = q.front().second;
                if((i-1)>=0 && grid[i-1][j] == 1) {q.push({i-1,j}); grid[i-1][j] = 2; }
                if((i+1)<n && grid[i+1][j] == 1) {q.push({i+1,j}); grid[i+1][j] = 2; }
                if((j-1)>=0 && grid[i][j-1] == 1) {q.push({i,j-1}); grid[i][j-1] = 2;}
                if((j+1)<m && grid[i][j+1] == 1) {q.push({i, j+1}); grid[i][j+1] = 2;}
                
                q.pop();
            }
            
            minute++;
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++) if(grid[i][j] == 1) return -1; //If any fresh orange left. Non reachable.
        }
        
        return minute;
    }
};