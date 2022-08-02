//ITEMS CAN BE TAKEN MORE THAN ONCE - INFINITE SUPPLY
#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    int f(int index, int capacity, vector<vector<int>> &item, vector<vector<int>> &dp){
        int weight = 0, value = 1;
        if(index==0){
            return  (capacity/item[0][weight])*item[0][value];
        }

        if(dp[index][capacity]!=-1) return dp[index][capacity];
        int notTake = 0 + f(index-1, capacity, item, dp);
        int take = -1e8;
        if(item[index][weight]<=capacity)   take = item[index][value] + f(index, capacity-item[index][weight], item, dp);

        return (dp[index][capacity] = max(take, notTake));
    }

    int unboundKnap(vector<vector<int>> item, int maxWeight){
        int n = item.size()-1;
        vector<vector<int>> dp(n+1, vector<int>(maxWeight+1, -1));
        return f(n, maxWeight, item, dp);
    }

    int unboundKnapOPT(vector<vector<int>> item, int maxWeight){
        int n = item.size()-1;
        int weight = 0, value = 1;
        vector<vector<int>> dp(n+1, vector<int>(maxWeight+1, 0));

        for(int i=0; i<=maxWeight; i++) dp[0][i] = (i/item[0][weight])*item[0][value];

        for(int index=1; index<=n; index++){
            for(int capacity=0; capacity<=maxWeight; capacity++){
                int notTake = 0 + dp[index-1][capacity];
                int take = -1e8;
                if(item[index][weight]<=capacity)   take = item[index][value] + dp[index][capacity-item[index][weight]];

                dp[index][capacity] = max(take, notTake);
            }
        }

        return dp[n][maxWeight];


        return 0;
    }

}; 

int main(){
    vector<vector<int>> item = {{2,5}, {4,11}, {6,13}};
    int maxWeight = 10;

    Solution newSol;
    cout << newSol.unboundKnapOPT(item, maxWeight);
    return 0;
}