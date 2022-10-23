// LeetCode - 48. Rotate Image.
// You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
// You have to rotate the image in-place, which means you have to modify the input 2D matrix directly.

// Method To Rotate Matrix:
// 1. Reverse the order of rows in the matrix.
// 2. Take transpose.

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    //Method Of Rotating: 
    //1. Interchange Or Reverse Rows: Top & Bottom
    //2. Take Transpose
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        //Reverse Rows:
        for(int i=0; i<(n/2); i++){
            for(int j=0; j<n; j++){
                swap(matrix[i][j], matrix[(n-1)-i][j]);
            }
        }
        
        //Take Transpose:
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        return;
    }
};