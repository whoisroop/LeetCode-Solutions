//Concept Of MatrixChainMultiplication
#include<bits/stdc++.h>
using namespace std;

class Solution{
private:
    //Find the min cost of cutting a stick (i...j) long when cuts allowed are given.
    int f(int i, int j, vector<int> &cuts, vector<vector<int>> &dp){
        if(i>j) return 0;

        if(dp[i][j]!=-1)    return dp[i][j];
        int cost = 0;
        int mini = 1e9;
        for(int p=i; p<=j; p++){
            cost = (cuts[j+1]-cuts[i-1]) + f(i, p-1, cuts, dp) + f(p+1, j, cuts, dp);
            if(cost<mini)   mini = cost;
        }

        return dp[i][j] = mini;
    }

public:
    int minCost(vector<int> &cuts, int length){
        cuts.push_back(0);
        cuts.push_back(length);
        sort(cuts.begin(), cuts.end());   
        //Sorting Is Important: Subproblems generated are independent.
        int lastIndex = cuts.size()-1;
        vector<vector<int>> dp(lastIndex+1, vector<int>(lastIndex+1, 0));

        // return f(1, lastIndex-1, cuts, dp);

        //BaseCase
        // for(int i=0; i<=lastIndex; i++){
        //     for(int j=0; j<=lastIndex; j++){
        //         if(i>j) dp[i][j]=0;
        //     }
        // }
        
        for(int i=lastIndex-1; i>=1; i--){
            for(int j=i; j<=lastIndex-1; j++){
                int mini = 1e9;
                for(int p=i; p<=j; p++){
                    int cost = (cuts[j+1]-cuts[i-1]) + dp[i][p-1] + dp[p+1][j];
                    if(cost<mini)   mini = cost;
                }

                dp[i][j] = mini;
            }
        }

        return dp[1][lastIndex-1];
    }

};

int main(){
    vector<int> cuts = {3,5,1,4};
    int length = 7;
    Solution newSol;
    cout << newSol.minCost(cuts, length);

    return 0;
}