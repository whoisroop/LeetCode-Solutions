#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int f(int m, int n, vector<vector<int>> &grid, vector<vector<int>> &dp){
        
        if(n<0 || n>(grid.size()-1)) return 1e9;
        if(m==0)    return grid[0][n];
        if(dp[m][n]!=-1)    return dp[m][n];
        
        int pathA = f(m-1, n-1, grid, dp);
        int pathB = f(m-1, n, grid, dp);
        int pathC = f(m-1, n+1, grid, dp);
        
        return dp[m][n] = (grid[m][n] + min(pathA, min(pathB, pathC)));
    }
        
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int M = matrix.size();
        int N = matrix[0].size();
        vector<vector<int>> dp(M, vector<int>(N, -1));
        int mini = 1e9;
        for(int i=0; i<N; i++){
            mini = min(mini, f(M-1, i, matrix, dp));
        }
        
        return mini;
    }

    int optimizedSolution(vector<vector<int>> &grid){
        int N = grid.size();
        vector<vector<int>> dp(N, vector<int>(N, 0));

        for(int i=0; i<N; i++)  dp[0][i] = grid[0][i];  //BaseCase

        for(int row=1; row<N; row++){
            for(int i=0; i<N; i++){
                int pathA=1e9, pathB=1e9, pathC=1e9;
                pathA = grid[row][i] + dp[row-1][i];
                if(i-1>=0) pathB = grid[row][i] + dp[row-1][i-1];
                if(i+1<N) pathC = grid[row][i] + dp[row-1][i+1];

                dp[row][i] = min(pathA, min(pathB, pathC));
            }
        }

        int mini = 1e9;
        for(int i: dp[N-1]){
            mini = min(mini, i);
        }

        return mini;
    }
};

int main(){
    vector<vector<int>> grid = {{17,82}, {1,-44}};
    Solution newSol;
    cout << newSol.optimizedSolution(grid);
    return 0;
}