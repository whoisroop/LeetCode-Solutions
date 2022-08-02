#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Solution {
public:
    bool f(int ia, int ib, int ic, string &sa, string &sb, string &sc, vector<vector<vector<int>>> &dp){
        if(ic==0){
            if(ia == 0 && ib == 0)  return true;
            return false;
        }
        if(dp[ia][ib][ic]!=-1)  return dp[ia][ib][ic];

        if(ia>0 && ib>0){
            if(sc[ic-1] == sa[ia-1] && sc[ic-1] == sb[ib-1]){
            return dp[ia][ib][ic] = (f(ia-1, ib, ic-1, sa, sb, sc, dp) || f(ia, ib-1, ic-1, sa, sb, sc, dp));    
            }
        }
        
        if(ia>0 && sc[ic-1] == sa[ia-1]){
            return dp[ia][ib][ic] = f(ia-1, ib, ic-1, sa, sb, sc, dp);
        }
        
        if(ib>0 && sc[ic-1] == sb[ib-1]){
            return dp[ia][ib][ic] = f(ia, ib-1, ic-1, sa, sb, sc, dp);
        }

        else return false;
        
    }
    bool isInterleave(string sa, string sb, string sc) {
        int la = sa.size();
        int lb = sb.size();
        int lc = sc.size();
        vector<vector<vector<int>>> dp(la+1, vector<vector<int>>(lb+1, vector<int>(lc+1, -1)));

        if(lc != la+lb) return false;
        if(lc<2){
            if(lc==0 && la == 0 && lb == 0)   return true;
            if(la==1 && sc[0]==sa[0])   return true;
            if(lb==1 && sc[0]==sb[0])   return true;
        }
        return f(la, lb, lc, sa, sb, sc, dp);
    }

    bool isInterleaveOPT(string sa, string sb, string sc) {
        int la = sa.size();
        int lb = sb.size();
        int lc = sc.size();
        vector<vector<vector<int>>> dp(la+1, vector<vector<int>>(lb+1, vector<int>(lc+1, 0)));

        if(lc != la+lb) return false;
        if(lc<2){
            if(lc==0)   return true;
            if(la==1 && sc[0]==sa[0])   return true;
            if(lb==1 && sc[0]==sb[0])   return true;
        }

        //BASECASE
        dp[0][0][0] = 1;
        if(sc[0]==sa[0])   dp[1][0][1] = 1;
        if(sc[0]==sb[0])   dp[0][1][1] = 1;

        // for(int i=1; i<=la; i++){ //INITIALIZED WITH 0
        //     for(int j=1; j<=lb; j++){
        //         dp[i][j][0] = 0;
        //     }
        // }

        for(int ia = 0; ia<=la; ia++){
            for(int ib = 0; ib<=lb; ib++){
                for(int ic = 1; ic<=lc; ic++){

                    if(ia>0 && ib>0){
                        if(sc[ic-1] == sa[ia-1] && sc[ic-1] == sb[ib-1]){
                            dp[ia][ib][ic] = (dp[ia-1][ib][ic-1] || dp[ia][ib-1][ic-1]);   
                        }
                    }
                    
                    else if(ia>0 && sc[ic-1] == sa[ia-1]){
                        dp[ia][ib][ic] = dp[ia-1][ib][ic-1];
                    }
                    
                    else if(ib>0 && sc[ic-1] == sb[ib-1]){
                        dp[ia][ib][ic] = dp[ia][ib-1][ic-1];
                    }

                    else dp[ia][ib][ic] = 0;
                    
                }
            }
        }

        for(int ia = 0; ia<=la; ia++){
            for(int ib = 0; ib<=lb; ib++){
                for(int ic = 0; ic<=lc; ic++){
                    cout << dp[ia][ib][ic] << " ";
                }
                cout << endl;
            }
            cout << endl;
         }


        return dp[la][lb][lc];
    }
};

int main(){
    string sa = "aabcc";
    string sb = "dbbca";
    string sc = "aadbbcbcac";
    Solution newSol;
    cout << newSol.isInterleaveOPT(sa, sb, sc);
    

    return 0;
}