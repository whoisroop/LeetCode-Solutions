// LeetCode - 73. Set Matrix Zero.
// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's. Implement Inplace.

#include<iostream>
#include<vector>
#include<unordered_set>

// Traverse through the matrix and store the rows and columns of the cell with entry zero.
// Store only unique row and column : Use Set Data Structure.

using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        unordered_set<int> zeroR;
        unordered_set<int> zeroC;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]==0){
                    zeroR.insert(i); zeroC.insert(j);
                }
            }
        }
        
        for(const int &x: zeroR){
            for(int j=0; j<m; j++){
                matrix[x][j] = 0;
            }
        }
        
        for(const int &x: zeroC){
            for(int i=0; i<n; i++){
                matrix[i][x] = 0;
            }
        }

        //Print Matrix:
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++)  cout << matrix[i][j] << " ";
            cout << endl;
        }
    }
};

int main(){
    vector<vector<int>> matrix = {{0,1,2,0}, {3,4,5,2}, {1,3,1,5}};
    Solution set;
    set.setZeroes(matrix);

    return 0;
}
