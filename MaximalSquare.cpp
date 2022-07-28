#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:    
    int maxSquareArea(vector<vector<int>> &grid){
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> squares(n, vector<int>(m, 0));  //Squares ending at right bottom at i, j.

        for(int i=0; i<n; i++)  squares[i][0] = grid[i][0] - '0';
        for(int j=0; j<m; j++)  squares[0][j] = grid[0][j] - '0';

        int maxi = 1;
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(grid[i][j]=='1'){
                    squares[i][j] =  1 + min(squares[i-1][j-1], min(squares[i-1][j], squares[i][j-1]));
                    if(squares[i][j]>maxi) maxi = squares[i][j];
                }
            }
        }

        return (maxi*maxi);
    }

};

