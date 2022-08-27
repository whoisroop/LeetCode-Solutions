#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    //Write a recursive function to calculate the length of longest common subsequence.
    //Concept: ABC | DAC The i & j might match or might not.
    //If not matching move i once & then j once simultaneously creating two branch in the recursion.
    
    //Why to use DP? We're using recursion & can have multiple branches, a single branch will surely calculate the required parameter so store that as we will not need to go down that path again.

    //Recursion Code:
    int find(string &sa, string &sb, int ia, int ib, vector<vector<int>> &dp){
        if(ia<0 || ib<0) return 0;  //If either of string is exhausted.

        if(dp[ia][ib]!=-1)  return dp[ia][ib];
        int longest = 0;
        if(sa[ia] == sb[ib]) longest = 1 + find(sa, sb, ia-1, ib-1, dp);
        else{
            longest = max( find(sa, sb, ia-1, ib, dp), find(sa, sb, ia, ib-1, dp) );
        }

        return dp[ia][ib] = longest;
    }

    //Tabulation Code:
    int findLCS(string sa, string sb){
        int la = sa.size();
        int lb = sb.size();
        vector<vector<int>> dp(la+1, vector<int>(lb+1, -1));

        //Tabulation & Index Shifting:
        //BASE CASE: 
        for(int i=0; i<=lb; i++) dp[0][i] = 0;
        for(int i=0; i<=la; i++) dp[i][0] = 0;

        for(int ia=0; ia<=la; ia++){
            for(int ib=0; ib<=lb; ib++){
                if(ia==0 || ib==0) continue;  //If either of string is exhausted.

                int longest = 0;
                if(sa[ia-1] == sb[ib-1]) longest = 1 + dp[ia-1][ib-1];
                else{
                    longest = max( dp[ia-1][ib] , dp[ia][ib-1] );
                }

                dp[ia][ib] = longest;
            }
        }

        return dp[la][lb];
    }

    //DP[i][j] - Stores the length of longest common subsequence of stringA[0...i] & stringB[0...j]. 
    //Hence by comparing the DP[i-1][j-1] with DP[i][j] (DP[i][j] = DP[i-1][j-1] + 1) & checking if stringA[i]==stringB[j] we can conclude if the ith or jth character are a part of the LCS.

    //Print LCS Code:
    string printLCS(string sa, string sb){
        int la = sa.size();
        int lb = sb.size();
        vector<vector<int>> dp(la+1, vector<int>(lb+1, -1));

        //Tabulation & Index Shifting:
        //BASE CASE: 
        for(int i=0; i<=lb; i++) dp[0][i] = 0;
        for(int i=0; i<=la; i++) dp[i][0] = 0;

        for(int ia=0; ia<=la; ia++){
            for(int ib=0; ib<=lb; ib++){
                if(ia==0 || ib==0) continue;  //If either of string is exhausted.

                int longest = 0;
                if(sa[ia-1] == sb[ib-1]) longest = 1 + dp[ia-1][ib-1];
                else{
                    longest = max( dp[ia-1][ib] , dp[ia][ib-1] );
                }

                dp[ia][ib] = longest;
            }
        }

        //In order to print the LCS understanding the meaning of the DP array is of utmost importance.
        //DP[X][Y] : The max possible size of common subsequence of stringA[0...X] & stringB[0...Y].
        //Making the DP table, we'll understand how to retrace the solution.

        string lcs = "";
        int i=la; int j=lb;
        while(i>0){
            while(j>0){
                if(sa[i-1]==sb[j-1]){
                    lcs += sa[i-1];
                    i=i-1; j=j-1;
                    continue;
                }
                else{
                    if(dp[i-1][j]>dp[i][j-1]) i=i-1;
                    else j=j-1;
                }
            }
        }

        reverse(lcs.begin(), lcs.end());
        return lcs;
    }
};

int main(){
    string sa = "ABCDA";
    string sb = "ADCBA";
    Solution find;
    cout << find.printLCS(sa, sb);
    return 0;
}