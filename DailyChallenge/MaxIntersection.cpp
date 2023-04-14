// GFG: Max Intersecting Lines
// Description -N horizontal line segments are arranged on the X-axis of a 2D plane. The start and end point of each line segment is given in a Nx2 matrix lines[ ][ ]. Your task is to find the maximum number of intersections possible of any vertical line with the given N line segments.

// Approach: Sweep Line Algorithm

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxIntersections(vector<vector<int>> lines, int N) {
        vector<int> start(N, 0), end(N, 0);
        for(int i=0; i<N; i++){
            start[i] = lines[i][0];
            end[i] = lines[i][1];
        }
        
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        
        int counter = 0;
        int maxV = 1;
        int j=0;
        for(int i=0; i<N; i++){
            while(end[j] < start[i]){
                j += 1; counter -= 1;
            }
            
            counter += 1;
            maxV = max(maxV, counter);
        }
        
        return maxV;
    }
};

int main(){
    Solution solve;
    
    return 0;
}