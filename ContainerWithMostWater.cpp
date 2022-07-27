#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    int maxWater(vector<int> &height){
        int n = height.size();
        int i=0, j=(n-1);
        int maxWater = 0;

        // for(int i=0; i<n; i++){
        //     for(int j=(i+1); j<n; j++){
        //         int mini = min(height[i], height[j]);
        //         int water = mini*(j-i);
        //         maxWater = max(maxWater, water);
        //     }
        // }

        int mini=0;
        while(i<j){
            mini = min(height[i], height[j]);
            int water = mini*(j-i);
            maxWater = max(maxWater, water);
            cout << "I: " << i << " J: " << j << " | Water: " << water << endl;

            if(height[j]>height[i]) i++;
            else j--;
        }

        
        return maxWater;
    }

};

int main(){
    vector<int> height = {1,3,2,5,25,24,5};
    Solution newSol;
    cout << newSol.maxWater(height);

    return 0;
}