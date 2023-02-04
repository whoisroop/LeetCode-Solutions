// LeetCode - 51. N Queens.
// Description - 
// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
// Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool is_safe(int i, int j, unordered_set<int> &R, unordered_set<int> &C, unordered_set<int> &DA, unordered_set<int> &DB){
        if(R.find(i) != R.end()) return false;
        if(C.find(j) != C.end()) return false;
        if(DA.find(i+j) != DA.end()) return false;
        if(DB.find(i-j) != DB.end()) return false;

        return true;
    }
    
    void placeQueen(int Q, vector<string> &grid, unordered_set<int> &R, unordered_set<int> &C, unordered_set<int> &DA, unordered_set<int> &DB, vector<vector<string>> &solution){
        if(Q < 0){ solution.push_back(grid); return; }
        int n = grid.size();

        int i = Q;
        for(int j=0; j<n; j++){
            // PLACE:
            if(is_safe(i, j, R, C, DA, DB)){
                R.insert(i); C.insert(j);
                DA.insert((i+j)); DB.insert((i-j));
                grid[i][j] = 'Q';

                placeQueen(Q - 1, grid, R, C, DA, DB, solution);

                grid[i][j] = '.';
                R.erase(i); C.erase(j);
                DA.erase((i+j)); DB.erase((i-j));
            }
        }

        return;
    }

    vector<vector<string>> solveNQueens(int n) {
        if(n == 1) return {{"Q"}};
        else if(n <= 3) return {};
        
        string layout(n, '.');
        vector<string> grid(n, layout);

        unordered_set<int> R, C, DA, DB;
        vector<vector<string>> solution;

        placeQueen(n - 1, grid, R, C, DA, DB, solution);
        return solution;
    }
};

int main(){
    Solution solve;
    
    return 0;
}