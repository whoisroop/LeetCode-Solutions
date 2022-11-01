// LeetCode - 42. Trapping Rain Water.

#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    int trap(vector<int> &height){
        int n = height.size();
        vector<int> lMax(n, 0); //Max height on left side of a block.
        vector<int> rMax(n, 0); //Max height on right side of a block.
        
        lMax[0] = height[0]; 
        rMax[n-1] = height[n-1];

        for(int i=1; i<n; i++){
            lMax[i] = max(height[i], lMax[i-1]); 
        }

        for(int i=(n-2); i>=0; i--){
            rMax[i] = max(height[i], rMax[i+1]);
        }

        int water = 0;
        for(int i=1; i<(n-1); i++){
            water += min(lMax[i], rMax[i]) - height[i];
        }

        return water;
    }
};