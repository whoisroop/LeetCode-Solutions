// You are given a rectangular cake of size h x w and two arrays of integers horizontalCuts and verticalCuts where:

// horizontalCuts[i] is the distance from the top of the rectangular cake to the ith horizontal cut and similarly, and
// verticalCuts[j] is the distance from the left of the rectangular cake to the jth vertical cut.
// Return the maximum area of a piece of cake after you cut at each horizontal and vertical position provided in the arrays horizontalCuts and verticalCuts. Since the answer can be a large number, return this modulo 109 + 7.
#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Solution{
public:
    int mod = (1e9+7);
    int maxArea(int height, int width, vector<int> verticalCuts, vector<int> horizontalCuts){
        verticalCuts.insert(verticalCuts.begin(), 0);
        horizontalCuts.insert(horizontalCuts.begin(), 0);
        verticalCuts.push_back(width);
        horizontalCuts.push_back(height);

        sort(verticalCuts.begin(), verticalCuts.end());
        sort(horizontalCuts.begin(), horizontalCuts.end());

        int n=verticalCuts.size();
        int m=horizontalCuts.size();

        int y=0 , x=0;
        for(int i=1; i<n; i++){
            y = max(y, (verticalCuts[i]-verticalCuts[i-1]));
        }
        for(int j=1; j<m; j++){
            x = max(x, (horizontalCuts[j]-horizontalCuts[j-1]));
        }

        long long int area = (1LL*x*y);

        if(area>(1e9+7))    return (int)(area%mod);
        return area;
    }
};

int main(){
    int height = 1e9, width = 1e9;
    vector<int> verticalCuts = {2};
    vector<int> horizontalCuts = {2};

    Solution newSol;
    cout << newSol.maxArea(height, width, verticalCuts, horizontalCuts);
}