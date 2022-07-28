//Find number of ways from top left cell to bottom right cell.
#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    int grid(int m, int n){
        // MxN size of matrix.
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return gridWays(m-1, n-1, dp);
    }

    int gridWays(int x, int y, vector<vector<int>> &dp){
        // if(x>=0 && y>=0 && matrix[x][y]==-1) return 0;   //Edge Case: DEAD END CELL
        if(x == 0 && y == 0)  return 1; //Destination Reached
        if(x<0 || y<0)  return 0;   //Destination Not Reached

        if(dp[x][y]!=-1)    return dp[x][y];

        int left = gridWays(x-1, y, dp);
        int up = gridWays(x, y-1, dp);

        return dp[x][y] = (left+up);
    }

};

int main(){
    int m = 4;
    int n = 3;
    Solution newSol;
    cout << newSol.grid(m, n);
    return 0;
}