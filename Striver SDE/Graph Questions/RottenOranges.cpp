// GFG - Rotten Oranges.
// Description - Find the time required to for all the oranges to rot.
// A[i][j] =
// 0: EMPTY, 1: Fresh Orange, 2: Rotten Orange
// Find the maximum distance between the rotten & fresh orange, that will be the maximum time required.

#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Multisource BFS
        vector<vector<int>> A = grid;
        int imax = grid.size(), jmax = grid[0].size();
        
        queue<pair<pair<int, int>, int>> q;
        for(int i=0; i<imax; i++){
            for(int j=0; j<jmax; j++) if(A[i][j] == 2) q.push({{i, j}, 0});
        }
        
        // L R B T
        vector<int> moveX = {-1, 1, 0, 0};
        vector<int> moveY = {0, 0, -1, 1};
        
        vector<vector<int>> visited(imax, vector<int>(jmax, 0));
        int maxD = 0;
        while(!q.empty()){
            auto top = q.front(); q.pop();
            int i = top.first.first, j = top.first.second;
            int distance = top.second;
            
            maxD = max(maxD, distance);
            for(int k=0; k<4; k++){
                int inew = i+moveX[k];
                int jnew = j+moveY[k];
                
                if(inew >= 0 && inew < imax && jnew >= 0 && jnew < jmax && A[inew][jnew] == 1 && visited[inew][jnew] == 0){
                    q.push({{inew, jnew}, distance + 1});
                    visited[inew][jnew] = 1;
                }
            }
        }
        
        for(int i=0; i<imax; i++){
            for(int j=0; j<jmax; j++) if(A[i][j] == 1 && visited[i][j] == 0) return -1;
        }
        
        return maxD;
    }
};

int main(){
    Solution solve;
    
    return 0;
}