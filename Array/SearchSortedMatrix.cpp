// GFG: Search in a row-column sorted Matrix.
// Description: Given a matrix of size n x m, where every row and column is sorted in increasing order, and a number x. Find whether element x is present in the matrix or not.
// Approach: Range Of Matrix: [A[0][0], A[N-1][M-1]]

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    //Function to search a given number in row-column sorted matrix.
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

int main(){
    Solution solve;
    
    return 0;
}