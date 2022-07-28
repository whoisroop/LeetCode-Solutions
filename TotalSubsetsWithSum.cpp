//Find number of subsets with given sum.
#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    int f(int index, int target, vector<int> &array, vector<vector<int>> &dp){
        if(target==0)   return 1;
        if(index==0)    return (target==array[0]);  //If target == array[0] - 1 else 0.
        if(dp[index][target]!=-1)   return dp[index][target];

        int pick=0, notPick=0;
        if(array[index]<=target)    pick = f(index-1, (target-array[index]), array, dp);
        notPick = f(index-1, target, array, dp);

        return (dp[index][target] = (pick+notPick));
    }

    int findSubsets(vector<int> array, int sum){
        int n = array.size()-1;
        vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));

        return f(n, sum, array, dp);
    }

    int optimized(vector<int> array, int sum){
        int n = array.size()-1;
        vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));

        for(int i=0; i<=n; i++) dp[i][0] = 1;
        dp[0][array[0]] = 1;

        for(int index=1; index<=n; index++){
            for(int target=1; target<=sum; target++){
                int pick=0, notPick=0;
                if(array[index]<=target)    pick = dp[index-1][target-array[index]];
                notPick = dp[index-1][target];

                dp[index][target] = (pick+notPick);
            }
        }

        return dp[n][sum];
    }

};

int main(){
    vector<int> A = {3,2,5};
    Solution newSol;
    cout << newSol.optimized(A, 5);
    return 0;
}