#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int findLCS(string sa, string sb){
        int la = sa.size();
        int lb = sb.size();
        vector<vector<int>> dp(la+1, vector<int>(lb+1, -1));

        //Tabulation & Index Shifting:
        //BASE CASE: 
        for(int i=0; i<=la; i++) dp[i][0] = 0;
        for(int i=0; i<=lb; i++) dp[0][i] = 0;

        for(int ia=1; ia<=la; ia++){
            for(int ib=1; ib<=lb; ib++){
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
};

int main(){
    string a = "12321";
    string b = "32147";
    Solution find;
    cout << find.findLCS(a, b);
    return 0;
}