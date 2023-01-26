// You are given a black & white image in form of m*n pixel matrix grid.

// if pixel[i][j] = 0 then pixel is black
// if pixel[i][j] = 1 then pixel is white
// Calculate maximum greyness of image.
// Where greyness of a pixel[i][j] = (number of 1s in ith row + number of 1s in jth column) - (number of 0s in ith row + number of 0s in jth column)
// 0's in row = (m - 1's in row) & 0's in columns = (n - 1's in columns)

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<vector<int>> greyness(vector<string> & grid){
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> grey(n, vector<int>(m, 0)); //To store greyness.

        vector<int> ones_row(n, 0);
        vector<int> ones_col(m, 0);

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1'){ ones_row[i] += 1; ones_col[j] += 1; }
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                grey[i][j] = 2*(ones_row[i] + ones_col[j]) - (m + n);
            }
        }

        return grey;
    }
};

int main(){
    Solution find;
    vector<string> grid = { "101", "001", "110" };

    vector<vector<int>> grey = find.greyness(grid);

    int n = grid.size();
    int m = grid[0].size();

    for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cout << grey[i][j] << " ";
            }
            cout << endl;
        }

    return 0;
}