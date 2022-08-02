//Refer StocksIII
//Right after sell you can't buy the next day. Cool down: 1 day.
#include<iostream>
#include<vector>
using namespace std;

class Solution{
private:
    int f(int day, int buy, int days, vector<int> &price, vector<vector<int>> &dp){
        if(day>=days)    return 0;

        if(dp[day][buy]!=-1)  return dp[day][buy];
        if(buy){
            int pathA = (-price[day]) + f(day+1, 0, days, price, dp);
            int pathB = 0 + f(day+1, 1, days, price, dp);
            return dp[day][buy] = max(0, max(pathA, pathB));
        }

        else{
            //If not allowed then skip that day. Assume the next day doesn't exist.
            int pathA = (+price[day]) + f(day+2, 1, days, price, dp); 
            int pathB = 0 + f(day+1, 0, days, price, dp);
            return dp[day][buy] = max(pathA, pathB);
        }
    }

public:
    int maxProfit(vector<int> &prices){
        int totalDays = prices.size();
        vector<vector<int>> dp(totalDays+1, vector<int>(2, -1));
        return f(0, 1, totalDays, prices, dp);
    }

};