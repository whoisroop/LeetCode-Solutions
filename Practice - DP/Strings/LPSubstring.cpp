//LeetCode 5: Longest Palindromic Substring.
#include<iostream>
#include<vector>
using namespace std;

class Solution{
private:
    //Extract the string & check if it is palindrome or not.
    string checkPalindrome(int i, int j, vector<vector<int>> &dp, string &s){
        string p = "";
        while(dp[i][j]!=0){
            p += s[i-1];

            dp[i][j]=-1;    //Mark Visited
            i--; j--;
        }

        cout << p;
        int length = p.size();

        //Starting from the middle move towards the end to find the max possible palindromic substring of the given string p.

        int start=(length-1)/2; int end=(length-1)/2;
        if(length%2==0) end = end+1;

        while(start>=0){
            if(p[start]!=p[end]) break;
            start--; end++;
        }
        start++; end--;

        return p.substr(start, (end-start+1));
    }

public:
    //First calculate the DP table for LCSubstring.
    string LPSubstring(string &sa){
        int la = sa.size(); int lb = sa.size();
        
        if(la<2) return sa;

        string sb = ""; for(int i=la-1; i>=0; i--) sb+=sa[i]; 
        vector<vector<int>> dp(la+1, vector<int>(lb+1, -1));

        //BASE CASE:
        for(int i=0; i<=la; i++) dp[i][0] = 0;
        for(int i=0; i<=lb; i++) dp[0][i] = 0;

        for(int ia=0; ia<=la; ia++){
            for(int ib=0; ib<=lb; ib++){
                if(ia==0 || ib==0) continue;

                int longest=0;
                if(sa[ia-1]==sb[ib-1]) longest = 1 + dp[ia-1][ib-1];
                else longest = 0;

                dp[ia][ib] = longest;
            }
        }

        for(int i=0; i<=la; i++){
            for(int j=0; j<=lb; j++) cout << dp[i][j] << " ";
            cout << endl;
        }

        //Now check if the substrings are palindrome or not.
        string palindrome = "";
        int maxi=0;

        for(int i=la; i>=0; i--){
            for(int j=lb; j>=0; j--){
                if(dp[i][j]>0){
                    string p = checkPalindrome(i, j, dp, sa);
                    if(p.size()>maxi){
                        maxi = p.size();
                        palindrome = p;
                    }
                } 
            }
        }

        return palindrome;
    }
};

int main(){
    string sa = "aacxycaa";    //aacdefcaa aacfedcaa
    Solution find;
    cout << find.LPSubstring(sa);
    return 0;
}
