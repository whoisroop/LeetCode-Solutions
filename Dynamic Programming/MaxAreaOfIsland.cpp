#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    int f(int i, int j, int imax, int jmax, vector<vector<int>> &grid){
        // if(i<0 || i>imax || j<0 || j>jmax)  return 0;
        grid[i][j]=0;
        int pathA=0, pathB=0, pathC=0, pathD=0;
        if((j+1<=jmax) && grid[i][j+1]==1) pathA = f(i, j+1, imax, jmax, grid);    //Right
        if((j-1>=0) && grid[i][j-1]==1) pathB = f(i, j-1, imax, jmax, grid);    //Left
        if((i+1<=imax) && grid[i+1][j]==1) pathC = f(i+1, j, imax, jmax, grid);    //Bottom
        if((i-1>=0) && grid[i-1][j]==1)  pathD = f(i-1, j, imax, jmax, grid);    //Up
        
        return (1 + (pathA+pathB+pathC+pathD));
    }

    int maxAreaOfIsland(vector<vector<int>> &grid){
        int imax = grid.size()-1;
        int jmax = grid[0].size()-1;

        int maxi=0;
        int area=0;
        for(int i=0; i<=imax; i++){
            for(int j=0; j<=jmax; j++){
                if(grid[i][j]==1){
                    cout << "ISLAND! Found: " << i << " " << j << " | ";
                    area = f(i, j, imax, jmax, grid);
                    maxi = max(maxi, area);
                    cout << "AREA: " << area << endl;
                }
            }
        }

        return maxi;
    }
};

int main(){
    vector<vector<int>> gridX = {
        {0,0,1,0,0,0},
        {0,0,0,0,0,0},
        {0,0,1,0,1,0},
        {0,1,1,0,1,1},
        {0,1,0,1,0,0},
        {0,0,1,1,1,1}
    };

    vector<vector<int>> gridY = {
        {0,0,1,0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,1,1,0,1,0,0,0,0,0,0,0,0},
        {0,1,0,0,1,1,0,0,1,0,1,0,0},
        {0,1,0,0,1,1,0,0,1,1,1,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,0,0,0,0,0,0,1,1,0,0,0,0}
    };

    vector<vector<int>> gridZ = {
        {0,1},
        {1,1}
    };

    Solution newSol;
    cout << newSol.maxAreaOfIsland(gridY);

    return 0;
}