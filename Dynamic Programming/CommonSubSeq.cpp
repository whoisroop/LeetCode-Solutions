//Find the length of longest common subsequence of the given two strings.
#include<iostream>
#include<vector>
using namespace std;

class Solution{
private:
    int f(int a, int b, string &sa, string &sb, vector<vector<int>> &dp){
        if(a<0 || b<0)  return 0;

        if(dp[a][b]!=-1)    return dp[a][b];
        if(sa[a]==sb[b]){
            int path = 1 + f(a-1, b-1, sa, sb, dp);
            return dp[a][b] = path;
        }
        else{
            int pathA = 0 + f(a-1, b, sa, sb, dp);
            int pathB = 0 + f(a, b-1, sa, sb, dp);
            return dp[a][b] = max(pathA, pathB);
        }
    }

public:
    int lcs(string sa, string sb){
        int la = sa.size(), lb = sb.size();
        vector<vector<int>> dp(la, vector<int>(lb, -1));
        return f(la-1, lb-1, sa, sb, dp);
    }

    int lcsOPT(string sa, string sb){
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

        return dp[la][lb];
    }

};

int main(){
    string A = "a";
    string B = "ced";
    Solution newSol;
    cout << newSol.lcs(A, B);

    return 0;
}