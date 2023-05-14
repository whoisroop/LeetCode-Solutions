// GFG - Flood Fill.
// Description - 
// There are cases where the "visited" state cannot be represented by the color, such as if the input image only has a limited range of color values or if the new color we're filling in happens to be the same as one of the existing color values in the image. In those cases, we would need to use a different way to represent the visited state, such as a separate memoization table or a boolean flag for each cell.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int imax = image.size(), jmax = image[0].size();
        
        vector<vector<int>> A = image;
        
        queue<pair<int, int>> q;
        q.push({sr, sc});
        int detect = A[sr][sc];
        A[sr][sc] = color;
        vector<vector<bool>> visited(imax, vector<bool>(jmax, false));
        
        vector<int> moveX = {-1, 1, 0, 0};
        vector<int> moveY = {0, 0, -1, 1};
        while(!q.empty()){
            auto top = q.front(); q.pop();
            int i = top.first, j = top.second;
            
            for(int k=0; k<4; k++){
                int ni = i+moveX[k];
                int nj = j+moveY[k];
                
                if(ni>=0 && nj>=0 && ni<imax && nj<jmax && A[ni][nj] == detect && !visited[ni][nj]){
                    q.push({ni, nj});
                    A[ni][nj] = color;
                    visited[ni][nj] = true;
                }
            }
        }
        
        return A;
    }
};

int main(){
    Solution solve;
    
    return 0;
}