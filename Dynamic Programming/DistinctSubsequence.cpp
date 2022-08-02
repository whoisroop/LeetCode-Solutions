#include<iostream>
#include<vector>
using namespace std;

class Solution{
private:
    //Find the distinct subsequence sb[0...ib-1] in the given string sa[0...ia-1].
    int f(int ia, int ib, string &sa, string &sb, vector<vector<int>> &dp){
        if(ib<0)    return 1;
        if(ia<0)    return 0;
        if(ia<ib)   return 0;   //Subsequence Length > String Length

        if(dp[ia][ib]!=-1)  return dp[ia][ib];
        if(sa[ia]==sb[ib]){
            int pathA = f(ia-1, ib-1, sa, sb, dp);    //Matched & Taken
            int pathB = f(ia-1, ib, sa, sb, dp);  //Matched & Not Taken
            return dp[ia][ib] = pathA+pathB;
        }
        else{
            int path = f(ia-1, ib, sa, sb, dp);
            return dp[ia][ib] = path;
        }
    }

public:
    int find(string sa, string sb){
        int la = sa.size();
        int lb = sb.size();
        vector<vector<int>> dp(la, vector<int>(lb, -1));

        return f(la-1, lb-1, sa, sb, dp);
    }

};

int main(){
    string sa = "babgbag";
    string sb = "bag";
    Solution newSol;
    cout << newSol.find(sa, sb);

    return 0;
}