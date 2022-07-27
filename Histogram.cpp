#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution{
public:
    vector<int> nextSmallerElement(vector<int> &array){
        int n = array.size();
        vector<int> nse(n, -1);
        stack<int> stk;

        int x;
        for(int i=(n-1); i>=0; i--){
            x = array[i];
            while((!stk.empty()) && (array[stk.top()]>=x)){
                stk.pop();
            }

            if(!stk.empty())    nse[i] = stk.top();
            stk.push(i);
        }

        return nse;
    }

    vector<int> prevSmallerElement(vector<int> &array){
        int n = array.size();
        vector<int> nse(n, -1);
        stack<int> stk;

        int x;
        for(int i=0; i<=(n-1); i++){
            x = array[i];
            while((!stk.empty()) && (array[stk.top()]>=x)){
                stk.pop();
            }

            if(!stk.empty())    nse[i] = stk.top();
            stk.push(i);
        }

        return nse;
    }

    int maxArea(vector<int> height){
        int n = height.size();
        //Find The Next Smaller & Previous Smaller Element
        vector<int> nse = nextSmallerElement(height);
        vector<int> pse = prevSmallerElement(height);
        int area = 0;
        int maxArea = 0;
        for(int i=0; i<n; i++){
            if(nse[i]==-1)  nse[i]=n;
            nse[i]-=1;  //To adjust the histrogram indexing.
            area = height[i]*((nse[i]-pse[i]));
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }

};

int main(){
    vector<int> height = {2,1,5,6,2,3};
    Solution newSol;
    cout << newSol.maxArea(height);

    return 0;
}