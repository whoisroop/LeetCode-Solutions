// You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
// On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.
// Find and return the maximum profit you can achieve.
#include<iostream>
#include<vector>
using namespace std;

class Solution{
private:
    //Max profit to buy and sell stocks from (day...lastDay) given price[day].
    int f(int day, int buy, vector<int> &price, int lastDay, vector<vector<int>> &dp){
        if(day==(lastDay+1))    return 0;

        if(dp[day][buy]!=-1)    return dp[day][buy];
        if(buy){
            int pathA = (-price[day]) + f(day+1, 0, price, lastDay, dp);  //Buy
            int pathB = 0 + f(day+1, 1, price, lastDay, dp);    //NotBuy
            return dp[day][buy] = max(0, max(pathA, pathB));   //To avoid loss. Buy & Sell On Same Day.
        }
        else{
            int pathA = (+price[day]) + f(day+1, 1, price, lastDay, dp);  //Sell
            int pathB = 0 + f(day+1, 0, price, lastDay, dp);    //NotSell
            return dp[day][buy] = max(pathA, pathB);
        }
    }

public:
    int maxProfit(vector<int> &price){
        int n = price.size()-1;
        vector<vector<int>> dp(n+1, vector<int>(2, -1));    //For Each Day: Buy NotBuy
        return f(0, 1, price, n, dp);
    }

    int maxProfitOPT(vector<int> price){
        int n = price.size()-1;
        vector<vector<int>> dp(n+2, vector<int>(2, 0));    //For Each Day: Buy NotBuy

        //BaseCase
        dp[n+1][0] = dp[n+1][1] = 0;    //Beyond Last Day

        for(int day=n; day>=0; day--){
            for(int buy=1; buy>=0; buy--){
                if(buy){
                int pathA = (-price[day]) + dp[day+1][0];  //Buy
                int pathB = 0 + dp[day+1][1];    //NotBuy
                dp[day][buy] = max(0, max(pathA, pathB));   //To avoid loss. Buy & Sell On Same Day.
            }
            else{
                int pathA = (+price[day]) + dp[day+1][1];  //Sell
                int pathB = 0 + dp[day+1][0];    //NotSell
                dp[day][buy] = max(pathA, pathB);
            }
        }
    }

    return dp[0][1];    //On Day = 0 No Stocks Left Buy = 1
}

};

int main(){
    vector<int> price = {7,1,5,3,6,4};
    Solution newSol;
    cout << newSol.maxProfitOPT(price);
    
    return 0;
}