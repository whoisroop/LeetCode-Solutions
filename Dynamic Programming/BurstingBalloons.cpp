#include<iostream>
#include<vector>
using namespace std;

class Solution{
private:
    int f(int i, int j, vector<int> &cost, vector<vector<int>> &dp){
        if(i>j) return 0;

        if(dp[i][j]!=-1)    return dp[i][j];

        int value = 0;
        int maxi = -1e8;
        for(int p=i; p<=j; p++){
            value = cost[i-1]*cost[p]*cost[j+1] + f(i, p-1, cost, dp) + f(p+1, j, cost, dp);
            if(value>maxi)  maxi = value;
        }

        return dp[i][j] = maxi;
    }

public:
    int maxCoins(vector<int> cost){
        cost.insert(cost.begin(), 1);
        cost.insert(cost.end(), 1);
        int li = cost.size()-1;

        vector<vector<int>> dp(li+1, vector<int>(li+1, -1));

        return f(1, li-1, cost, dp);
    }

    int maxCoinsOPT(vector<int> cost){
        cost.insert(cost.begin(), 1);
        cost.insert(cost.end(), 1);
        int li = cost.size()-1;

        vector<vector<int>> dp(li+1, vector<int>(li+1, 0));

        for(int i=li-1; i>=1; i--){
            for(int j=1; j<=li-1; j++){
                if(i>j) continue;
                int value = 0;
                int maxi = -1e8;
                for(int p=i; p<=j; p++){
                    value = cost[i-1]*cost[p]*cost[j+1] + dp[i][p-1] + dp[p+1][j];
                    if(value>maxi)  maxi = value;
                }

                dp[i][j] = maxi;
            }
        }

        return dp[1][li-1];
    }
};

int main(){
    vector<int> cost = {3,1,5,8};
    Solution newSol;
    cout << newSol.maxCoinsOPT(cost);
    return 0;
}