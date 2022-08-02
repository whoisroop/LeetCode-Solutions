// Print the longest common subsequence.
#include<iostream>
#include<vector>
using namespace std;
//sa - string a, la - length a
class Solution{
public:
    int lcss(string sa, string sb){
        int la = sa.size(), lb = sb.size();
        vector<vector<int>> dp(la+1, vector<int>(lb+1, -1));
        //BASE CASE
        for(int i=0; i<=la; i++) dp[i][0] = 0;
        for(int i=0; i<=lb; i++) dp[0][i] = 0;

        int maxi=0;
        for(int a=1; a<=la; a++){
            for(int b=1; b<=lb; b++){
                if(sa[a-1]==sb[b-1]){
                    int path = 1 + dp[a-1][b-1];
                    dp[a][b] = path;
                    maxi = max(maxi, dp[a][b]);
                }
                else{
                    dp[a][b] = 0;   //THE CHANGE: dp[a][b] represents length of substring (previously subsequence) till length a, b.
                }
            }
        }

        return maxi;
    }

};

int main(){
    string sa = "abcde";
    string sb = "bcedc";
    Solution newSol;
    cout << newSol.lcss(sa, sb);
}