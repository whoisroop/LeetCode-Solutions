#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    int f(int i, bool start, vector<int> &array, vector<vector<int>> &dp){
        if(i<0){
            if(start!=true) return 0;
            else return -1e8;
        }

        if(dp[i][start]!=-1) return dp[i][start];
        if(start){  //Sub Array not yet started.
            int take = array[i] + f(i-1, false, array, dp);
            int notTake = 0 + f(i-1, true, array, dp);
            return dp[i][start] = max(take, notTake);
        }
        else{
            int include = array[i] + f(i-1, false, array, dp);
            int notInclude = 0;
            return dp[i][start] = max(include, notInclude);
        }
    }

    int findMaxSubarraySum(vector<int> &array){
        int li = array.size()-1;
        if(li==0)   return array[0];
        vector<vector<int>> dp(li+1, vector<int>(2, -1));
        return f(li, true, array, dp);
    }

    int findMaxSumOPT(vector<int> &array){
        int li = array.size()-1;
        if(li==0)   return array[0];
        vector<vector<int>> dp(li+2, vector<int>(2, 0));   //Coordinate Shifting

        //Base Case
        dp[-1 + 1][1] = -1e8;
        dp[-1 + 1][0] = 0;

        for(int i=0; i<=(li); i++){
            for(int start=0; start<=1; start++){
                if(start){  //Sub Array not yet started.
                    int take = array[i] + dp[i-1 + 1][0];
                    int notTake = 0 + dp[i-1 + 1][1];
                    dp[i + 1][start] = max(take, notTake);
                }

                else{
                    int include = array[i] + dp[i-1 + 1][0];
                    int notInclude = 0;
                    dp[i + 1][start] = max(include, notInclude);
                }
            }
        }

        return dp[li + 1][1];
    }

    //O(n) Solution
    int findMSS(vector<int> &array){
        int n = array.size();
        int maxi = array[0];  //Final answer.
        int sum = array[0];    //Started from previous index.
        for(int i=1; i<n; i++){
            sum = max(array[i], sum+array[i]);
            maxi = max(maxi, sum);
        }

        return maxi;
    }

};

int main(){
    vector<int> array = {-2,2,1,-10,1};
    Solution newSol;
    cout << newSol.findMSS(array);

    return 0;
}