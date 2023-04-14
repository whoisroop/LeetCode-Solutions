// GFG: Replace O With X 
// Description: Given a matrix mat of size N x M where every element is either O or X.
// Replace all O with X that are surrounded by X.
// A O (or a set of O) is considered to be surrounded by X if there are X at locations just below, just above, just left and just right of it.

// Approach: The group of O's touching the boundary will not be converted to X.
// Traverse along the boundary: Store the O's at the boundary.
// Do a mutisource BFS and mark all the O's that form a group touching the edge/boundary of the matrix.
// Convert the rest of O's in the matrix apart from the ones marked visited to X's.

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<vector<char>> fill(int imax, int jmax, vector<vector<char>> A){
        vector<vector<int>> visited(imax, vector<int>(jmax, 0));
        
        queue<pair<int, int>> q;
        // Left & Right Boundary:
        for(int i=0; i<imax; i++){
            if(A[i][0] == 'O'){ q.push({i, 0}); visited[i][0] = 1; }
            if(A[i][jmax-1] == 'O'){ q.push({i, jmax-1}); visited[i][jmax-1] = 1; }
        }
        
        // Top & Bottom Boundary:
        for(int j=0; j<jmax; j++){
            if(A[0][j] == 'O'){ q.push({0, j}); visited[0][j] = 1; }
            if(A[imax-1][j] == 'O'){ q.push({imax-1, j}); visited[imax-1][j] = 1; }
        }
        
        // Now perform BFS:
        while(!q.empty()){
            auto top = q.front(); q.pop();
            int i = top.first, j = top.second;
            
            if(i-1 >=0 && visited[i-1][j] != 1 && A[i-1][j] == 'O'){
                q.push({i-1, j});
                visited[i-1][j] = 1;
            }
            if(i+1 < imax && visited[i+1][j] != 1 && A[i+1][j] == 'O'){
                q.push({i+1, j});
                visited[i+1][j] = 1;
            }
            if(j-1 >=0 && visited[i][j-1] != 1 && A[i][j-1] == 'O'){
                q.push({i, j-1});
                visited[i][j-1] = 1;
            }
            if(j+1 < jmax && visited[i][j+1] != 1 && A[i][j+1] == 'O'){
                q.push({i, j+1});
                visited[i][j+1] = 1;
            }
        }
        
        for(int i=0; i<imax; i++){
            for(int j=0; j<jmax; j++){
                if(A[i][j] == 'O' && visited[i][j] == 0) A[i][j] = 'X';
            }
        }
        
        return A;
    }
};

int main(){
    Solution solve;
    
    return 0;
}