// LeetCode - Search 2D Matrix. 
// Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:
// 1. Integers in each row are sorted from left to right.
// 2. The first integer of each row is greater than the last integer of the previous row.

#include<iostream>
#include<vector>
using namespace std;

class Easy{
    public:
    bool search(vector<vector<int>> A, int n, int m, int value) {
        // Approach: Start from top right:
        // All the elements down: Columns will be greater.
        // All the element left: Row will be smaller.
        // Make movements as per the requirements: LEFT OR DOWN
        
        int i=0, j=m-1;
        while(i<n && j>=0){
            if(A[i][j] == value) return true;
            
            if(A[i][j] < value) i += 1;
            else j -= 1;
        }
    
        return false;
    }
};

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int i=0, j=n-1;
        int midpoint=0;
        
        
        //Binary Search On Column:
        while(i<=j){
            midpoint = (i+j)/2;
            
            if(matrix[midpoint][0] == target) {j = midpoint; break;}
            
            if(matrix[midpoint][0] < target) i = midpoint+1;
            else j = midpoint-1;
        }
        
        int row = j; 
        if(row<0) return false;
        
        i=0, j=m-1;
        //Binary Search On Row:
        while(i<=j){
            midpoint = (i+j)/2;
            
            if(matrix[row][midpoint] == target) {j = midpoint; break;}
            
            if(matrix[row][midpoint] < target) i = midpoint+1;
            else j = midpoint-1;
        }
        
        int column = j; 
        if(column<0) return false;
        
        cout << "ROW - " << row << " & COLUMN - " << column << " = " <<  matrix[row][column];
        if(matrix[row][column] == target) return true;
        else return false;
    }
};