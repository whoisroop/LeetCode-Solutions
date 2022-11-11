// GFG - Number Of Coins.
// Given a value V and array coins[] of size M, the task is to make the change for V cents, given that you have an infinite supply of each of coins{coins1, coins2, ..., coinsm} valued coins. Find the minimum number of coins to make the change. If not possible to make change then return -1.

#include<bits/stdc++.h>
using namespace std;

class Solution{

	public:
	int find(int index, int target, int coins[], vector<vector<int>> &DP){
	    if(target == 0) return 0;
	    if(index < 0) return 1e7;
	    
	    if(DP[index][target]!=-1) return DP[index][target];
	    
	    int pathA = 1e7;
	    if(coins[index] <= target) pathA = 1 + find(index, target-coins[index], coins, DP);
	    int pathB = 0 + find(index-1, target, coins, DP);
	    
	    return DP[index][target] = min(pathA, pathB);
	}
	
	int minCoins(int coins[], int N, int V){ 
	    vector<vector<int>> DP(N, vector<int>(V + 1, -1));
	    int mincoins = find(N-1, V, coins, DP);
	    
	    if(mincoins > V) return -1;
	    else return mincoins;
	} 
	  
};