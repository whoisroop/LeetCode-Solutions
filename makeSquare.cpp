#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    int f(int i, int target, vector<int> &length, vector<vector<int>> &dp){
        if(i==0){
            if(target==0 || target==length[0])   return 1;
            else return 0;
        }
        
        if(dp[i][target]!=-1)   return dp[i][target];
        
        int take = 0;
        if(length[i]<=target){
            int l = length[i];
            length[i]=-1;   //Once Taken
            take = f(i-1, target-length[i], length, dp);
        }
        int notTake = f(i-1, target, length, dp);
        return dp[i][target] = (take+notTake);
    }
    
public:
    bool makesquare(vector<int>& length) {
        int totalSum = 0;
        int n = length.size()-1;
        for(int i: length) totalSum+=i;
        cout << "TOTAL SUM: " << totalSum << endl;
        if(totalSum%4!=0)   return false;
        
        vector<vector<int>> dp(n+1, vector<int>((totalSum/4)+1, -1));
        int ways = f(n, totalSum/4, length, dp);
        cout << "WAYS: " << ways << endl;
        if(ways>=4) return true;
        else    return false;
    }
};

int main(){
    vector<int> l = {2,2,2,2,2,6};
    Solution newSol;
    cout << newSol.makesquare(l);

    return 0;
}