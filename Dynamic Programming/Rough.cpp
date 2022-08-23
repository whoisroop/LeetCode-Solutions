#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool f(int index, int target, vector<int> &array, vector<vector<int>> &dp){
        if(target==0) return true;
        if(index==0){
            if(target == array[0]) return true;
            else return false;
        }

        if(dp[index][target]!=-1) return dp[index][target];

        int notTake = f(index-1, target, array, dp);
        int take = false;
        if(target>=array[index]) take = f(index-1, target-array[index], array, dp);

        return dp[index][target] = (take||notTake);
    }

public:
    bool isPossible(vector<int> &array){
        int sum=0;
        for(const int &i: array) sum+=i;
        
        if(sum%2==0) sum=(sum/2);
        else return false;

        int li = array.size()-1;
        vector<vector<int>> dp(li+1, vector<int>(sum+1, -1));
        return f(li, sum, array, dp);
    }

    bool optimized(vector<int> &array){
        if(array.size()<2) return false;

        int sum=0;
        for(const int &i: array) sum+=i;
        
        if(sum%2==0) sum=(sum/2);
        else return false;

        int li = array.size()-1;
        vector<vector<int>> dp(li+1, vector<int>(sum+1, 0));    //DP[Index][Target]: Is it possible to achieve target in the array space of 0... Index
        
        //BaseCase:
        for(int i=0; i<=li; i++) dp[i][0] = 1;
        if(array[0]<=sum) dp[0][array[0]]=true;
        
        for(int index=1; index<=li; index++){
            for(int target=1; target<=sum; target++){
                int notTake = dp[index-1][target];
                int take = false;
                if(target>=array[index]) take = dp[index-1][target-array[index]];

                dp[index][target] = (take||notTake);
                cout << index << " " << target << " | " << dp[index][target] << endl;
            }
        }

        return dp[li][sum];
    }
};

int main(){
    vector<int> array = {9,5};
    Solution find;
    cout << find.optimized(array);

    return 0;
}