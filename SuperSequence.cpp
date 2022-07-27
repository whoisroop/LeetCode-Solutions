// Given two strings make a string (supersequence) such that the given strings are its subsequences.
#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Solution{
public:
    string superseq(string sa, string sb){
        int la = sa.size(), lb = sb.size();
        vector<vector<int>> dp(la+1, vector<int>(lb+1, -1));
        //BASE CASE
        for(int i=0; i<=la; i++) dp[i][0] = 0;
        for(int i=0; i<=lb; i++) dp[0][i] = 0;

        for(int a=1; a<=la; a++){
            for(int b=1; b<=lb; b++){
                if(sa[a-1]==sb[b-1]){
                    int path = 1 + dp[a-1][b-1];
                    dp[a][b] = path;
                }
                else{
                    int pathA = 0 + dp[a-1][b];
                    int pathB = 0 + dp[a][b-1];
                    dp[a][b] = max(pathA, pathB);
                }
            }
        }

        int l = dp[la][lb]; //Length Of LCS
        int ia = la, ib = lb;
        string ans = "";
        while(ia>0 && ib>0){    //1 Based Indexing: (Index 0: -1)
            if(sa[ia-1]==sb[ib-1]){
                ans += sa[ia-1];
                ia--;
                ib--;
            }

            else if(dp[ia-1][ib]>dp[ia][ib-1]){
                ans += sa[ia-1];
                ia--;
            }

            else{
                ans += sb[ib-1];
                ib--;
            }
        }

        while(ia>0){
            ans += sa[ia-1];
            ia--;
        }

        while(ib>0){
            ans += sb[ib-1];
            ib--;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }

};

int main(){
    string sa = "groot";
    string sb = "brute";
    Solution newSol;
    cout << newSol.superseq(sa, sb);

    return 0;
}