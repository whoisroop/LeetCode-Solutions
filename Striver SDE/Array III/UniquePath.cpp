// LeetCode - 62. Unique Paths.
// There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int path(int i, int j, vector<vector<int>> &DP){
        if(i==0 && j==0) return 1;
        
        if(DP[i][j]!=-1) return DP[i][j];
        
        int way=0;
        if((i-1)>=0) way+=path(i-1, j, DP);
        if((j-1)>=0) way+=path(i, j-1, DP);
        
        return (DP[i][j] = way);
    }
    
    int uniquePaths(int n, int m) {
        vector<vector<int>> DP(n, vector<int>(m, -1));
        
        return path(n-1, m-1, DP);
    }
};

