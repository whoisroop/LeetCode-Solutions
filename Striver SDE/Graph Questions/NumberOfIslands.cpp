// GFG: Number Of Islands
// Description - Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) consisting of '0's (Water) and '1's(Land). Find the number of islands.
// Note: An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
  void DFS(int i, int j, vector<vector<char>> &grid){
        int imax = grid.size(), jmax = grid[0].size();

        grid[i][j] = '0';
        for(int a=-1; a<=1; a++){
            for(int b=-1; b<=1; b++){
                if(i+a >= 0 && i+a<imax && j+b>=0 && j+b<jmax && grid[i+a][j+b] != '0') DFS(i+a, j+b, grid);
            }
        }

        return;
    }

public:
    int numIslands(vector<vector<char>> grid) {
        int imax = grid.size(), jmax = grid[0].size();
        int counter = 0;
        for(int i=0; i<imax; i++){
            for(int j=0; j<jmax; j++){
                if(grid[i][j] == '0') continue;

                counter += 1;
                DFS(i, j, grid);
            }
        }

        return counter;
    }

};

int main(){
    Solution solve;
    
    return 0;
}