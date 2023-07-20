// GFG - Stock Buy Sell
// Link - https://practice.geeksforgeeks.org/problems/stock-buy-and-sell2615/1
// Description - The cost of stock on each day is given in an array price[] of size n. Each day you may decide to either buy or sell the stock i at price[i], you can even buy and sell the stock on the same day, Find the maximum profit which you can get.

// Approach:
// As at a time only one stock can be bought and sold, buy less sell more.
// Check for pair A[i] & A[i+1]; If the price hikes the next day buy the stock:
//  1 2 3 4  : DAYS
// {1 2 3 1} : PRICE
// Buy DAY 1 sell DAY 2
// Buy DAY 2 sell DAY 3
// --------------------
// Net effect of buying on DAY 1 & selling on DAY 3: ((2-1) + (3-2)) OR (3-1) = PROFIT

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int stockBuyAndSell(int n, vector<int> &A) {
        int profit = 0;
        for(int i=0; i<n-1; i++) if(A[i] < A[i+1]) profit += (A[i+1] - A[i]);
        
        return profit;
    }
};

int main(){
    Solution solve;
    
    return 0;
}