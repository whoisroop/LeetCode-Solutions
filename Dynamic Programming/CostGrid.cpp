//Find Min Cost Path From Top Left To Bottom Right Cell.
#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    int grid(vector<vector<int>> &cost){
        // MxN size of matrix.
        int m = cost.size();
        int n = cost[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return gridSum(m-1, n-1, cost, dp);
    }

    int gridSum(int x, int y, vector<vector<int>> &cost, vector<vector<int>> &dp){
        if(x == 0 && y == 0)  return cost[0][0]; //Destination Reached
        if(x<0 || y<0)  return INT32_MAX;   //Destination Not Reached

        if(dp[x][y]!=-1)    return dp[x][y];

        int left = gridSum(x-1, y, cost, dp);
        int up = gridSum(x, y-1, cost, dp);
        return dp[x][y] = (cost[x][y] + min(left, up));
    }

    //TABULATION:
    int minPathSum(vector<vector<int>> &cost) {
        // MxN size of matrix.
        int m = cost.size();
        int n = cost[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        for(int x=0; x<m; x++){
            for(int y=0; y<n; y++){
                if(x==0 && y==0)    dp[x][y]=cost[0][0];
                
                else{
                    int left=INT32_MAX, up=INT32_MAX;
                    if(x>0) left = dp[x-1][y];
                    if(y>0) up = dp[x][y-1];
                    dp[x][y] = (cost[x][y] + min(left, up));
                }
            }
        }
        
        return dp[m-1][n-1];
    }

};

int main(){
    vector<vector<int>> cost = {{5,9,6}, {11,5,2}};
    Solution newSol;
    cout << newSol.grid(cost);
    return 0;
}