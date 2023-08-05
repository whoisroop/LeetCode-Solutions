// Problem - 0 1 Knapsack Problem
// Link - https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

#include<bits/stdc++.h>
using namespace std;

// Why Not Greedy?
// Example: (Value, Weight)
// (10, 3) (6, 2) (5, 2)
//   3.33    3      2.5
// Total capacity: 4
// Greedy will select (10,3) which isn't optimal.

// However, greedy can be used to solved fractional knapsack as all the best weight to value items will be selected.
// 01 Knapsack problem, the weight to value ration cannot solve the problem.

class Solution{
private:
    int maxtotal(int index, int C, int W[], int V[], int N, vector<vector<int>> &DP){
        if(index == N) return 0;
        
        if(DP[index][C] != -1) return DP[index][C];
        int take = 0; int ntake = 0;
        if(C >= W[index]) take = V[index] + maxtotal(index+1, C-W[index], W, V, N, DP);
        ntake = 0 + maxtotal(index+1, C, W, V, N, DP);
    
        return DP[index][C] = max(take, ntake);
    }
    
public:
    int knapSack(int C, int W[], int V[], int N) { 
       vector<vector<int>> DP(N+1, vector<int>(C+1, -1));
       
       return maxtotal(0, C, W, V, N, DP);
    }
};

int main(){
    Solution solve;
    
    return 0;
}