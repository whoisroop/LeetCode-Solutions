// You are given an array prices where prices[i] is the price of a given stock on the ith day.
// Find the maximum profit you can achieve. You may complete at most two transactions.
// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
#include<iostream>
#include<vector>
using namespace std;

class Solution{
private:
    //Return the max profit from buy & sell stocks from days :0...n
    int f(int day, int buy, int cap, int n, vector<int> &price, vector<vector<vector<int>>> &dp){
        if(cap==0 || day==(n+1))  return 0;

        if(dp[day][buy][cap]!=-1) return dp[day][buy][cap];
        if(buy){
            int pathA = (-price[day]) + f(day+1, 0, cap, n, price, dp); //Buy
            int pathB = 0 + f(day+1, 1, cap, n, price, dp); //Not Buy
            return dp[day][buy][cap] = max(0, max(pathA, pathB));
        }
        else{
            int pathA = (+price[day]) + f(day+1, 1, cap-1, n, price, dp);   //Sell
            int pathB = 0 + f(day+1, 0, cap, n, price, dp); //Not Sell
            return dp[day][buy][cap] = max(pathA, pathB);
        }
    }
public:
    int maxProfit(vector<int> &price, int maxTransactions){
        int n = price.size()-1;
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(maxTransactions+1, -1)));
        return f(0, 1, maxTransactions, n, price, dp);
    }

};

int main(){
    vector<int> price = {3,3,5,0,0,3,1,4};
    Solution newSol;
    cout << newSol.maxProfit(price, 2);

    return 0;
}