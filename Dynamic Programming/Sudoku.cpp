#include<iostream>
#include<vector>
using namespace std;

class Solution{
private:
    bool isValid(int row, int col, char c, vector<vector<char>> &board){
        int n = board.size();
        for(int i=0; i<n; i++){
            if(board[row][i] == c)  return false;   //Check the row
            if(board[i][col] == c)  return false;   //Check the column
            //Check in the 3x3 block.
            int rx = (row/3)*3 + (i/3); //Increase row after every 3 iterations.
            int cx = (col/3)*3 + (i%3); //Keep on traversing on the same 3 columns.
            if(board[rx][cx] == c)  return false;
        }

        return true;
    }

    bool f(vector<vector<char>> &board, int n){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){

                if(board[i][j]=='.'){
                    for(char c='1'; c<='9'; c++){
                        if(isValid(i, j, c, board)){
                            board[i][j] = c;    //Try all possible case.
                            //We only need a single solution.
                            if(f(board, n)==true)   return true;
                            board[i][j] = '.';  //BackTrack if not the solution configuration.
                        }
                    }

                    //If none 1-9 is a suitable option. BackTrack.
                    return false;
                }

            }
        }

        //No empty block.
        return true;
    }

public:
    void solveSudoku(vector<vector<char>> &board){
        f(board, board.size());
        int n = board.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        return;
    }

};

int main(){
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    Solution newSol;
    newSol.solveSudoku(board);

    
}