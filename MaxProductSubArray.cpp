#include<iostream>
#include<vector>
using namespace std;

//Find Max & Min Altogether
class Solution {
public:
    int maxProduct(vector<int>& array) {
        int li = array.size()-1;
        if(li==0)   return array[0];
        vector<vector<int>> dpMax(li+2, vector<int>(2, 0));   //Coordinate Shifting
        vector<vector<int>> dpMin(li+2, vector<int>(2, 0));   //Coordinate Shifting

        //Base Case
        dpMax[-1 + 1][1] = -1e3;
        dpMax[-1 + 1][0] = 1;
        dpMin[-1 + 1][1] = -1e3;
        dpMin[-1 + 1][0] = 1;

        for(int i=0; i<=(li); i++){
            for(int start=1; start>=0; start--){
                if(start){  //Sub Array not yet started.
                    int take = max(array[i] * dpMax[i-1 + 1][0], array[i] * dpMin[i-1 + 1][0]);
                    int notTake = 0 + dpMax[i-1 + 1][1];
                    dpMax[i + 1][start] = max(take, notTake);
                    dpMin[i + 1][start] = min(min(array[i] * dpMax[i-1 + 1][0], array[i] * dpMin[i-1 + 1][0]), dpMin[i-1 + 1][1]);
                }

                else{
                    int include = max(array[i] * dpMax[i-1 + 1][0], array[i] * dpMin[i-1 + 1][0]);
                    int notInclude = 1;
                    dpMax[i + 1][start] = max(include, notInclude);
                    dpMin[i + 1][start] = min(min(array[i] * dpMax[i-1 + 1][0], array[i] * dpMin[i-1 + 1][0]), notInclude);
                }
            }
        }

        return dpMax[li + 1][1];
    }

    //O(n) Solution
    int findMPS(vector<int> &array){
        int n = array.size();
        int maxi = array[0];    //Subarray product to for maximum.  HISTORY
        int mini = array[0];    //Subarray product to for minimum.  HISTORY
        int value = array[0];    //ANSWER. Contains overall maximum.

        //If the element is negative -(maximum) is minimum & vice versa.
        for(int i=1; i<n; i++){
            if(array[i]<0){ //Swap
                maxi = maxi + mini;
                mini = maxi - mini;
                maxi = maxi - mini;
            }

            if(array[i]==0){
                maxi=1; mini=1;
                if(value < 0)   value = 0;
                continue;
            }

            maxi = max(array[i], maxi*array[i]);
            mini = min(array[i], mini*array[i]);
            if(value < maxi)    value = maxi;
        }

        return value;
    }
};

int main(){
    vector<int> array = {-2,1,0,-1};
    Solution newSol;
    cout << newSol.findMPS(array);

    return 0;
}