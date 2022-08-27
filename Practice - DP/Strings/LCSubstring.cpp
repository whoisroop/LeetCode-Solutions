#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    //The Recursion DP & Tabulation DP table will be different. 
    //Always tackle LCS questions using tabulation:
    //Concept: All the characters one by one will be compared & using the concept of given max length of subsequence or substring of length of STRING A & B: (i-1, j-1) (i, j-1) (i-1, j) we can determine for the the length i & j by comparing the characters stringA[i] & stringB[j] & using the provided lengths.
    //DP[i][j] : Find the LCSubstring in stringA of length i & string B of length j.

    //Tabulation Code:
    int findLCS(string sa, string sb){
        int la = sa.size();
        int lb = sb.size();
        vector<vector<int>> dp(la+1, vector<int>(lb+1, -1));

        //Tabulation & Index Shifting:
        //BASE CASE: 
        for(int i=0; i<=lb; i++) dp[0][i] = 0;  //Empty ' '.
        for(int i=0; i<=la; i++) dp[i][0] = 0;

        int maxi = 0;
        for(int ia=0; ia<=la; ia++){
            for(int ib=0; ib<=lb; ib++){
                if(ia==0 || ib==0) continue;  //If either of string is exhausted.

                int longest = 0;
                if(sa[ia-1] == sb[ib-1]) longest = 1 + dp[ia-1][ib-1];
                else{
                    longest = 0;
                }

                maxi = max(maxi, longest);
                dp[ia][ib] = longest;
            }
        }

        return maxi;
    }
};

int main(){
    string sa = "ABDCAB";
    string sb = "ADBABC";
    Solution find;
    cout << find.findLCS(sa, sb);
    return 0;
}