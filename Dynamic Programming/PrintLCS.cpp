// Print the longest common subsequence.
#include<iostream>
#include<vector>
using namespace std;
//sa - string a, la - length a
class Solution{
private: 
    int f(int a, int b, string &sa, string &sb, vector<vector<int>> &dp){
        if(a==0 || b==0)  return 0;

        if(dp[a][b]!=-1)    return dp[a][b];
        if(sa[a-1]==sb[b-1]){
            int path = 1 + f(a-1, b-1, sa, sb, dp);
            return dp[a][b] = path;
        }
        else{
            int pathA = 0 + f(a-1, b, sa, sb, dp);
            int pathB = 0 + f(a, b-1, sa, sb, dp);
            return dp[a][b] = max(pathA, pathB);
        }
    }

    int lcs(string sa, string sb){
        int la = sa.size(), lb = sb.size();
        vector<vector<int>> dp(la+1, vector<int>(lb+1, -1));
        return f(la, lb, sa, sb, dp);
    }

public:
    string lcsOPT(string sa, string sb){
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

        int l = dp[la][lb]; //length of lcs
        string lcs = "";
        for(int i=0; i<l; i++)  lcs+="#";

        int n = l-1;
        int a=la, b=lb;
        while(a>0 && b>0){
            if(sa[a-1]==sb[b-1]){
                lcs[n]=sa[a-1];
                n-=1;
                a-=1;
                b-=1;
            }
            else{
                if(dp[a-1][b]>dp[a][b-1]) a--;
                else b--;
            }
        }

        return lcs;

    }

};

int main(){
    string sa = "abcde";
    string sb = "baed";
    Solution newSol;
    cout << newSol.lcsOPT(sa, sb);
}