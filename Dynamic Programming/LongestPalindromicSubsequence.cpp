//Find the length of longest common subsequence of the given two strings.
#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    int lps(string sa){
        string sb = "";
        for(int i = sa.size()-1; i>=0; i--) sb+=sa[i];

        //FIND THE COMMON SUBSEQUENCE OF String & Its Reverse
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
    string A = "aacabdkacaa";
    Solution newSol;
    cout << newSol.lps(A);

    return 0;
}