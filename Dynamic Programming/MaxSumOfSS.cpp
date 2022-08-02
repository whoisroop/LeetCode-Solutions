//Max sum of non adjacent subsequence : Tablulation Converted.
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int f(int n, vector<int> array, vector<int> &dp){   //n -> index
        if(n==0)    return array[0];    //We're at 0th index means 1st index is not selected so select the 0th index to max the sum.
        if(n<0)     return 0;

        if(dp[n] != -1)  return dp[n];
        else{
            int pick = array[n] + f(n-2, array, dp);
            int noPick = 0 + f(n-1, array, dp);
            dp[n] = max(pick, noPick);
            return dp[n];
        }
    }

    int maxSum(vector<int> array){
        int size = array.size();
        vector<int> dp(size, -1);
        return f(size-1, array, dp);
    }

    int maxSumOpt(vector<int> array){   //Tabulation
        int n = array.size() - 1; //Last Index
        // vector<int> dp(array.size(), -1);

        // dp[0] = array[0];
        int curr, prev, prev2;
        prev = array[0];
        prev2 = 0;

        for(int i=1; i<=n; i++){
            // int pick = array[i] + dp[i-2];
            int pick = array[i] + prev2;
            // if(i-2<0)   pick = array[i] + 0;
            // int notPick = 0 + dp[i-1];
            int notPick = 0 + prev;

            // dp[i] = max(pick, notPick);
            curr = max(pick, notPick);

            prev2 = prev;
            prev = curr;
        }

        // return dp[n];
        return curr;
    }
};

int main(){
    vector<int> array = {2,9,1,3};

    Solution newSol;
    cout << newSol.maxSumOpt(array);

    return 0;
}