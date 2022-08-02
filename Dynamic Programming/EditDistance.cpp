// Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.
// You have the following three operations permitted on a word:
// Insert a character, Delete a character, Replace a character
#include<iostream>
#include<vector>
using namespace std;

class Solution{
private:
    //Operations required to convert sa[0...ia+1] into sb[0...ib+1] (Converted To 1 Based Indexing)
    int f(int ia, int ib, string &sa, string &sb, vector<vector<int>> &dp){
        if(ia==0)    return ib;    //String A Exhausted: Inserting Remaning Elements Of B 
        if(ib==0)    return ia;    //String B Exhausted: Delete Remaining Elements Of A
        
        if(dp[ia][ib]!=-1)  return dp[ia][ib];

        if(sa[ia-1]==sb[ib-1]){
            int path = 0 + f(ia-1, ib-1, sa, sb, dp);
            return dp[ia][ib] = path;
        }
        else{
            //sa = 'ab|c|' sb = 'xy|z|' 
            int pathA = 1 + f(ia, ib-1, sa, sb, dp);    //Insertion sa = 'ab|c|z' sb = 'x|y|z'
            int pathB = 1 + f(ia-1, ib, sa, sb, dp);    //Deletion  sa = 'a|b|' sb = 'xy|z|'
            int pathC = 1 + f(ia-1, ib-1, sa, sb, dp);  //Replace   sa = 'a|b|z' sb = 'x|y|z'
            return dp[ia][ib] = min(pathA, min(pathB, pathC));
        }
    }

public:
    int minOperations(string sa, string sb){
        int la = sa.size();
        int lb = sb.size();
        vector<vector<int>> dp(la+1, vector<int>(lb+1, -1));

        return f(la, lb, sa, sb, dp);
    }

    int minOperationsOPT(string &sa, string &sb){
        int la = sa.size();
        int lb = sb.size();
        vector<vector<int>> dp(la+1, vector<int>(lb+1, 0));

        //BASE CASE
        for(int ib=0; ib<=lb; ib++) dp[0][ib] = ib;
        for(int ia=0; ia<=la; ia++) dp[ia][0] = ia;

        for(int ia=1; ia<=la; ia++){
            for(int ib=1; ib<=lb; ib++){
                if(sa[ia-1]==sb[ib-1]){
                    dp[ia][ib] = 0 +  dp[ia-1][ib-1];
                }
                else{
                    dp[ia][ib] = 1 + min(dp[ia][ib-1], min(dp[ia-1][ib], dp[ia-1][ib-1]));
                }
            }
        }
        return dp[la][lb];
    }

};


int main(){
    string sa = "horse";
    string sb = "ros";
    Solution newSol;
    cout << newSol.minOperationsOPT(sa,sb);

    return 0;
}