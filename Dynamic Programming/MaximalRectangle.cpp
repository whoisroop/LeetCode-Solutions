#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution{
public:
    int maxAreaHistogram(vector<int> &height){
        int n = height.size();
        stack<int> stk;

        //Find Previous Smaller Number
        vector<int> pse(n, 0);
        for(int i=0; i<n; i++){
            while(!(stk.empty()) && (height[stk.top()]>=height[i])){
                stk.pop();
            }

            if(stk.empty()!=true)   pse[i] = stk.top();
            else    pse[i] = -1;
            stk.push(i);
        }

        while(stk.empty() != true)  stk.pop();

        //Find Next Smaller Number
        vector<int> nse(n, 0);
        for(int i=(n-1); i>=0; i--){
            while(!(stk.empty()) && (height[stk.top()]>=height[i])){
                stk.pop();
            }

            if(stk.empty()!=true)   nse[i] = stk.top();
            else    nse[i] = n;
            stk.push(i);
        }

        int maxArea=0;
        int area;
        for(int i=0; i<n; i++){ 
            //Boundary Adjustment
            pse[i]+=1;
            nse[i]-=1;

            area = height[i]*(nse[i]-pse[i]+1);
            maxArea = max(maxArea, area);
        }

        return maxArea;

    }

    int maximalRectangle(vector<vector<int>> &grid){
        int n = grid.size();
        int m = grid[0].size();

        vector<int> height(m, 0);
        int maxArea=0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1)   height[j]++;
                else    height[j]=0;
            }
            maxArea = max(maxArea, maxAreaHistogram(height));
        }

        return maxArea;
    }
    
};

int main(){
    vector<vector<int>> grid = {
        {1,0,1,0,0},
        {1,0,1,1,1},
        {1,1,1,1,1},
        {1,0,0,1,0}
    };

    vector<vector<int>> gridA = {
        {0}
    };

    vector<vector<int>> gridB = {
        {1}
    };

    Solution newSol;
    cout << newSol.maximalRectangle(gridB) << endl;
    
    return 0;
}