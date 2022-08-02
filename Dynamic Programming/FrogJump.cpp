#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

//DP + Recursion Solution - DP 3 TakeUForward

class Solution {
public:
    int findMin(vector<int> array){
        int min = array[0];
        for(int x: array){
            if(x<min)   min = x;
        }
        return min;
    }

    int f(int n, int k, vector<int> energy, vector<int> &dp) {   
        //Energy cost for jump from i to j: energy[i] - energy[k]
        //Frog can jump from ith stair to: i+1, i+2, ..., i+k
        if(n == 0)  return 0;   //Last Stair Reached - Energy For 0th Stair to 0th Stair --> 0

        vector<int> branch(k, 0);
        
        if(dp[n]!=-1)   return dp[n];

        for(int i=1; i<=k; i++){
            if(n-i>=0){
                branch[i-1] = f(n-i, k, energy, dp) + abs(energy[n] - energy[n-i]);
            }

            else {
                branch[i-1] = INT32_MAX;
            }
        }
        
        return dp[n] = findMin(branch);
    }
    
    int frogJump(int n, int k, vector<int> &heights) {
        vector<int> dp(n+1, -1);
        return f(n, k, heights, dp);
    }
};

int main(){
    vector<int> heights = {30,10,60,10,60,50};
    int n = 6;
    int k = 2;

    Solution newSol;
    int x = newSol.frogJump(n-1, k, heights);
    cout << x;
    return 0;
}