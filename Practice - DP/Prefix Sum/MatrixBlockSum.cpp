//LeetCode - 1314. Matrix Block Sum.
//Given a m x n matrix mat and an integer k, return a matrix answer where each answer[i][j] is the sum of all elements mat[r][c] for:
// i - k <= r <= i + k,
// j - k <= c <= j + k, and
// (r, c) is a valid position in the matrix.

//Use the concept of prefix sum: Pre Computation.
//Whenever, the sum of subarray in case of 1D or any contigious set of elements i.e. block in 2D is required use the concept of precomputation for efficient computation.
//We need the top left & bottom right coordinates to calculate the sum of the block.

#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    vector<vector<int>> matrixSUM(vector<vector<int>> &matrix, int k){
        int n = matrix.size(); int m = matrix[0].size();
        vector<vector<int>> sum(n+1, vector<int>(m+1, 0));  //1 BASED INDEXING - To Tackle Edge Cases
        vector<vector<int>> grid(n, vector<int>(m, 0)); //Solution

        //Find the sum of blocks with top left: 0,0 & bottom right: i,j.
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                sum[i][j] = (sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1]) + matrix[i-1][j-1];
            }
        }

        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++){
                cout << sum[i][j] << " ";
            }
            cout << endl;
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                //(A,B) : Top Left
                int a = ((i-k)>=0)? (i-k) : 0;
                int b = ((j-k)>=0)? (j-k) : 0;
                //(P,Q) : Bottom Right
                int p = ((i+k)<n)? (i+k) : (n-1);
                int q = ((j+k)<m)? (j+k) : (m-1); 
                a++; b++; p++; q++; //Sum: 1 BASED INDEXING.

                grid[i][j] = sum[p][q] - (sum[p][b-1] + sum[a-1][q]) + sum[a-1][b-1];
                // cout << "I & J :" << i << " , " << j << " | (A,B) & (P, Q) : " << a << " , " << b << " & " << p << " , " << q << " - " << grid[i][j] << endl;
            }
        }

        return grid;
    }
};

int main(){
    vector<vector<int>> array = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    Solution find;
    find.matrixSUM(array, 1);

    return 0;
}