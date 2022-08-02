#include<iostream>
#include<vector>
#include<list>
#include<stack>
using namespace std;

class Solution {
private:
    //Find the longest increasing subsequence till index i with previous selected index pi.
    int f(int i, int pi, int n, vector<int> &array, vector<vector<int>> &dp){
        if(i<0) return 0;

        if(dp[i][pi]!=-1)   return dp[i][pi];
        int pathA=0;
        if((pi==n) ||  (array[i]<array[pi])){ 
            //Can Take: If allowed to choose, can take or cannot take.
            int take = 1 + f(i-1, i, n, array, dp);
            int notTake = 0 + f(i-1, pi, n,  array, dp); 
            pathA = max(take, notTake);
        }
        int pathB = 0 + f(i-1, pi, n, array, dp);  //Not Take

        return dp[i][pi] = max(pathA, pathB);
    }

public:
    int largestIncreasingSubsequence(vector<int> &array){
        int n = array.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return f(n-1, n, n, array, dp);
    }

    int largestIncreasingSubsequenceOPT(vector<int> &array){
        int n = array.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        //Coordinate shift i, 1 to tackle i<0.    (pi already shifted in f())
        for(int i=0; i<n; i++){
            for(int pi=(i+1); pi<(n+1); pi++){
                int pathA=0;
                if((pi==n) ||  (array[i]<array[pi])){ 
                    //Can Take: If allowed to choose, can take or cannot take.
                    int take = 1 + dp[i-1+1][i];
                    int notTake = 0 + dp[i-1+1][pi]; 
                    pathA = max(take, notTake);
                }
                int pathB = 0 + dp[i-1+1][pi];  //Not Take

                dp[i+1][pi] = max(pathA, pathB);

            }
        }
        
        return dp[n][n];
    }
};

int main(){
    vector<int> cuts = {1,3,4,5,2};
    Solution newSol;
    cout << newSol.largestIncreasingSubsequence(cuts) << endl;
    cout << newSol.largestIncreasingSubsequenceOPT(cuts);
    return 0;
}