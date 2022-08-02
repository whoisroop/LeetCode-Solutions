#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    bool f(int index, int target, vector<int> array, vector<vector<int>> &dp){
        if(target==0)   return true;

        if(index==0){
            if(target == array[0])  return true;
            else    return false;
        }

        if(dp[index][target]!=-1)   return dp[index][target];
        
        else{
            bool take = false, notTake = false;
            if(target>=array[index]) take = f(index-1, target-array[index], array, dp);
            notTake = f(index-1, target, array, dp);

            return dp[index][target] = (take||notTake);
        }
    }

    bool isThereSubset(vector<int> array, int sum){
        int n = array.size() - 1;
        vector<vector<int>> dp(n+1, vector<int>(1e5, -1));  //1e5: MaxSum/MaxTarget
        return f(n, sum, array, dp);
    }

    //Tabulation
    bool optIsThereSubset(vector<int> array, int target){
        int n = array.size() - 1;
        vector<int> prev(1e5, 0);  //For Index i-1
        vector<int> curr(1e5, 0);  //For Index i

        prev[array[0]] = 1;    //For Base Case Index 0
        prev[0] = curr[0] = 1;

        for(int i=1; i<=n; i++){
            for(int t=1; t<=target; t++){
                bool take = false, notTake = false;
                if(t>=array[i]) take = prev[t-array[i]];
                notTake = prev[t];

                curr[t] = (take||notTake);
            }

            prev = curr;
        }
        return prev[target];
    }

};

int main(){
    vector<int> array = {5,9,4,3};
    int sum = 21;
    Solution newSol;
    cout << newSol.optIsThereSubset(array, sum);
}