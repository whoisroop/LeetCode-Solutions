// LeetCode - 121. Best Time To Buy Sell Stocks.
// You are given an array prices where prices[i] is the price of a given stock on the ith day.
// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

// Example:
// Input: prices = [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.

// [7 1 5 3 6 4] : Price of each day.
// [7 1 1 1 1 1] : Minimum to the left of each index.
// [0 0 4 2 5 3] : Difference Or Max Profit. 

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        int minPrice = 1e9;
        int maxProfit = 0;
        for(int i=0; i<n; i++){
            minPrice = min(minPrice, prices[i]);
            maxProfit = max(maxProfit, (prices[i]-minPrice));    
        }
        
        return maxProfit;
    }
};

int main(){
    Solution find;
    vector<int> array = {7,1,5,3,6,4};

    cout << "Max Profit: " << find.maxProfit(array);
    return 0;
}