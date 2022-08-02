// Count Square Submatrices with All Ones
#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    int totalSquares(vector<vector<int>> &grid){
        int n = grid.size();
        int m = grid[0].size();

        int squares = 0;
        //Using the grid itself to store the squares ending at block i,j.
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(grid[i][j]==1){
                    grid[i][j] = min(grid[i-1][j-1], min(grid[i][j-1], grid[i-1][j])) + 1;
                    squares += grid[i][j];
                }
            }
        }

        //Sum the first row & column elements.
        for(int i=0; i<max(m,n); i++){  
            if(i<n) squares += grid[i][0];
            if(i<m) squares += grid[0][i];
        }

        squares = squares - grid[0][0]; //Grid[0][0] is added twice in the above summation.

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }

        return squares;
    }

};

int main(){
    vector<vector<int>> grid = {
      {1,0,1},
      {1,1,0},
      {1,1,0}  
    };

    Solution newSol;
    cout << newSol.totalSquares(grid);
}