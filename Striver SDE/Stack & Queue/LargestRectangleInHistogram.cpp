// LeetCode - 84. Largest Triangle In Histogram.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> height){
        int n = height.size();
        // Find Next Smaller & Previous Smaller:
        vector<int> nse(n, (n));  //Store Index
        vector<int> pse(n, (-1));
        stack<int> stk;

        for(int i=(n-1); i>=0; i--){
            while(!stk.empty() && height[stk.top()]>=height[i]) stk.pop();

            if(!stk.empty()) nse[i] = stk.top(); //Stack stores the index.
            stk.push(i);
        }

        while(!stk.empty()) stk.pop();  //Reset Stack
        for(int i=0; i<n; i++){
            while(!stk.empty() && height[stk.top()]>=height[i]) stk.pop();

            if(!stk.empty()) pse[i] = stk.top(); //Stack stores the index.
            stk.push(i);
        }

        int maxarea = 0;
        for(int i=0; i<n; i++){
            int area = (nse[i] - pse[i] - 1)*height[i];
            maxarea = max(maxarea, area);
        }

        return maxarea;
    }
};