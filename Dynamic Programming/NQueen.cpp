#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    bool isSafe(int row, int col, int n, vector<string> &board){
        int i=row;
        int j=col;
        
        while(i>=0 && j>=0){
            if(board[i][j]=='Q')    return false;
            i--;    j--;    //To upper left
        }
        
        i=row;  j=col;
        
        while(j>=0){
            if(board[i][j]=='Q')    return false;
            j--;    //To left
        }
        
        i=row;  j=col;
        
        while(i<=(n-1) && j>=0){
            if(board[i][j]=='Q')    return false;
            i++;    j--;    //To bottom left
        }

        // cout << "SAFE: " << row << " " << col << endl;
        return true;
    }
    
    void f(int j, int n, vector<string> &board, vector<vector<string>> &sol){
        if(j==n){
            sol.push_back(board);   return;
        }
        
        for(int i=0; i<n; i++){
            if(isSafe(i,j, n, board)){
                // cout << "QUEEN:- i: " << i << ", j: " << j << endl;
                board[i][j] = 'Q';
                f(j+1, n, board, sol);
                board[i][j] = '.';  //BackTrack
            }
        }
        
        return;
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> solution;
        f(0, n, board, solution);

        // for(auto board: solution){
        //     for(string row: board)    cout << row << endl;
        //     cout << "----" << endl;
        // }
        
        return solution;
    }
};

int main(){
    Solution newSol;
    newSol.solveNQueens(4);

    return 0;
}