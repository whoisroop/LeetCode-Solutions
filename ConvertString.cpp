// Using the concept of LCS
#include<iostream>
#include<vector>
using namespace std;

class Solution{
private:
    int f(int ia, int ib, string &sa, string &sb, vector<vector<int>> &dp){
        if(ia==0 || ib==0)    return 0;

        if(dp[ia][ib]!=-1)  return dp[ia][ib];

        if(sa[ia-1]==sb[ib-1]){
            int path = 1 + f(ia-1, ib-1, sa, sb, dp);
            return dp[ia][ib] = path;
        }

        else{
            int pathA = 0 + f(ia-1, ib, sa, sb, dp);
            int pathB = 0 + f(ia, ib-1, sa, sb, dp);
            return dp[ia][ib] = max(pathA, pathB);
        }
    }

    int lcs(string sa, string sb){
        int la = sa.size();
        int lb = sb.size();
        vector<vector<int>> dp(la+1, vector<int>(lb+1, -1));
        return f(la, lb, sa, sb, dp);
    }
    
public:
    int minOperations(string sa, string sb){
        int llcs = lcs(sa, sb);
        return ((sa.size()-llcs) + (sb.size()-llcs)); //DELETION + INSERTIONS
    }

};

int main(){
    string sa = "abc";
    string sb = "dbbca";

    Solution newSol;
    cout << newSol.minOperations(sa, sb);

    return 0;
}