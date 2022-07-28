#include<iostream>
#include<vector>
using namespace std;

class Solution{
private:
    int f(int i, int li, vector<int> &array, vector<int> &dp){
        if(i==li)   return 0;
        if(array[i]==0) return 1e8;

        if(dp[i]!=-1)   return dp[i];

        int mini = 1e8;
        int jumps = 1e8;
        //array[i]: Max Jump From ith Index - (i+j)
        for(int j=1; j<=array[i]; j++){
            if(i+j<=(li))  jumps = 1 + f(i+j, li, array, dp);
            mini = min(mini, jumps);
        }

        return  dp[i] = mini;
    }

public:
    int minJumps(vector<int> &array){
        int li = array.size()-1;
        vector<int> dp(li+1, -1);

        return f(0, li, array, dp);
    }

    int minJumpsOPT(vector<int> &array){
        int li = array.size()-1;
        vector<int> dp(li+1, 1e8);
        
        dp[li]=0;
        int mini, jumps;
        for(int i=(li-1); i>=0; i--){
            mini = 1e8;
            jumps = 1e8;
            //array[i]: Max Jump From ith Index - (i+j)
            for(int j=1; j<=array[i]; j++){
                if(i+j<=(li))  jumps = 1 + dp[i+j];
                mini = min(mini, jumps);
            }

            dp[i] = mini;
        }

        return dp[0];
    }

};

int main(){
    vector<int> array = {5,9,3,2,1,0,2,3,3,1,0,0};
    Solution newSol;

    cout << newSol.minJumpsOPT(array);

    return 0;
}