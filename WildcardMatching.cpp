// Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:
// '?' Matches any single character.
// '*' Matches any sequence of characters (including the empty sequence).
// The matching should cover the entire input string (not partial).
#include<iostream>
#include<vector>
using namespace std;

class Solution{
private: 
    //sa: string | sb: pattern *?
    //Function: Is it possible to convert sa[0...ia] into sb[0...ib]
    //Converted to 1 based indexing
    bool f(int ia, int ib, string &sa, string &sb, vector<vector<int>> &dp){ 
        if(ia<0 && ib<0)    return true;
        if(ia>=0 && ib<0)    return false;
        if(ia<0 && ib>=0){   //To convert pattern into empty string all characters should be *
            for(int i=0; i<=ib; i++) if(sb[i] != '*')  return false;
            return true;
        }

        if(dp[ia][ib]!=-1)  return dp[ia][ib];

        if(sa[ia]==sb[ib] || sb[ib]=='?')   return dp[ia][ib] = f(ia-1, ib-1, sa, sb, dp);
        if(sb[ib]=='*'){
            bool pathA = f(ia, ib-1, sa, sb, dp);   //Consider Empty
            bool pathB = f(ia-1, ib, sa, sb, dp);   //Of Single Character
            return dp[ia][ib] = (pathA||pathB);
        }

        return dp[ia][ib] = false;
    }

public:
    bool wild(string s, string p){
        int ls = s.length();
        int lp = p.length();
        vector<vector<int>> dp(ls, vector<int>(lp, -1));

        return f(ls-1, lp-1, s, p, dp);
    }

};

int main(){
    string s = "";
    string p = "*";
    Solution newSol;
    cout << newSol.wild(s, p);

    return 0;
}