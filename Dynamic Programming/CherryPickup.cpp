#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int f(int x1, int y1, int x2, int y2, vector<vector<int>> &grid, vector<vector<vector<vector<int>>>> &dp){
        if((x1<0) || (x2<0) || (y1<0) || (y2<0))     return -1e8;
        if(grid[x1][y1]==-1 || grid[x2][y2]==-1)  return -1e8;

        if(x1==0 && x2==0 && y1==0 && y2==0){
            return grid[0][0];
        }
        if(dp[x1][y1][x2][y2]!=-1)  return dp[x1][y1][x2][y2];

        //Explore all the paths.
        int maxi = -1e8;
        int pathA = grid[x1][y1] + f(x1, y1-1, x2, y2-1, grid, dp);
        if(x1!=x2 && y1!=y2)     pathA += grid[x2][y2];
        int pathB = grid[x1][y1] + f(x1, y1-1, x2-1, y2, grid, dp);
        if(x1!=x2 && y1!=y2)     pathB += grid[x2][y2];
        int pathC = grid[x1][y1] + f(x1-1, y1, x2, y2-1, grid, dp);
        if(x1!=x2 && y1!=y2)     pathC += grid[x2][y2];
        int pathD = grid[x1][y1] + f(x1-1, y1, x2-1, y2, grid, dp);
        if(x1!=x2 && y1!=y2)     pathD += grid[x2][y2];

        maxi = max(pathA, max(pathB, max(pathC, pathD)));
        dp[x1][y1][x2][y2] = maxi;

        return maxi;
    }

    int cherryPickup(vector<vector<int>> &grid) {
        int n = grid.size();  //Last Index
        vector<vector<vector<vector<int>>>> dp(n, vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(n, -1))));

        int result = f(n-1, n-1, n-1, n-1, grid, dp);
        if(result<0)    return 0;
        else return result; //If there's no actual way.
    }
};

int main(){
    vector<vector<int>> grid = {{0,1,-1}, {1,0,-1}, {1,1,1}};
    //{{1,1,-1}, {1,-1,1}, {-1,1,1}};
    Solution newSol;
    cout << newSol.cherryPickup(grid);
    return 0;
}