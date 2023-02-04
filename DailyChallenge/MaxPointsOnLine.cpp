// LeetCode - 149. Max Points on a Line
// Description - Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, return the maximum number of points that lie on the same straight line.

// The slope alone won't do the job, we need a point and a slope to uniquely define a line.

#include<bits/stdc++.h>
using namespace std;

class Solution{
private:

public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n <= 2) return n;

        int maxcount = 1;
        for(int i = 0; i<n; i++){
            //To store the frequency of points having same slope origining from points[i].
            unordered_map<double, int> fmap; // Slope - Count
            int xA = points[i][0], yA = points[i][1];

            for(int j = 0; j<n; j++){
                if(i == j) continue;
                
                int xB = points[j][0], yB = points[j][1];
                double slope = (xA != xB) ? (1.0*yB-yA)/(xB-xA) : INT32_MAX;
                
                fmap[slope]++;

                maxcount = max(maxcount, fmap[slope]);
            }
        }
        
        return (maxcount + 1); // + 1 For the origin point.
    }
};

int main(){
    Solution solve;
    
    return 0;
}