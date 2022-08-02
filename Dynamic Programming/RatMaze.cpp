#include<iostream>
#include<vector>
using namespace std;

class Solution{
private:
    void f(int i, int j, int N, string &move, vector<vector<int>> &grid, vector<string> &solution){
        //Move from 0,0 to n-1, n-1
        //grid[i][j] = 1 : Allowed To Move | grid[i][j] = 0 : Not Allowed To Move
        
        if(i==(N-1) && j==(N-1)){
            solution.push_back(move);
            return;
        }

        //Down Move
        if((i+1)<N && grid[i+1][j]==1){
            grid[i][j] = 0; //Mark Can Not Visit Again
            move.push_back('D');
            f(i+1, j, N, move, grid, solution);
            move.pop_back();    //RESET (BackTrack)
            grid[i][j] = 1; 
        } 

        if((j-1)>=0 && grid[i][j-1]==1){
            grid[i][j]=0;
            move.push_back('L');
            f(i, j-1, N, move, grid, solution);
            move.pop_back();
            grid[i][j]=1;
        }

        if((j+1)<N && grid[i][j+1]==1){
            grid[i][j]=0;
            move.push_back('R');
            f(i, j+1, N, move, grid, solution);
            move.pop_back();
            grid[i][j]=1;
        }

        if((i-1)>=0 && grid[i-1][j]==1){
            grid[i][j]=0;
            move.push_back('U');
            f(i-1, j, N, move, grid, solution);
            move.pop_back();
            grid[i][j]=1;
        }

        return;
    }

public:
    vector<string> findPath(vector<vector<int>> &grid){
        int n = grid.size();
        vector<string> solution;
        string move;

        //If start point or end point blocked.
        if(grid[0][0]==0 || grid[n-1][n-1]==0){
            solution.push_back("-1");
            return solution;
        }

        f(0, 0, n, move, grid, solution);

        //If no path found.
        if(solution.size()==0)
        {
            solution.push_back("-1");
            return solution;
        }

        return solution;
    }

};

int main(){
    vector<vector<int>> grid = {
        {1, 0, 0, 0},
        {1, 1, 0, 1}, 
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };
    vector<vector<int>> gridX = {
        {0,1,1,1},
        {1,1,1,0}, 
        {1,0,1,1},
        {0,0,1,1}
    };

    Solution newSol;
    vector<string> solution = newSol.findPath(gridX);

    for(string i: solution) cout << i << endl;
    
    return 0;
}