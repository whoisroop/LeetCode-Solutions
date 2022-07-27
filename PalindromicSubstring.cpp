#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string sa) {
        string sb = "";
        int l = sa.size();
        for(int i=l-1; i>=0; i--)   sb+=sa[i];
        
        vector<vector<int>> dp(l+1, vector<int>(l+1, 0));
        //BaseCase: Not Required Already 0
        int maxi=0;
        int a=0, b=0;
        for(int ia=1; ia<=l; ia++){
            for(int ib=1; ib<=l; ib++){
                if(sa[ia-1]==sb[ib-1]){
                    dp[ia][ib] = dp[ia-1][ib-1] + 1;
                    if(dp[ia][ib]>maxi){
                        a=ia;
                        b=ib;
                        maxi = dp[ia][ib];
                    }
                }
            }
        }

        cout << sa << " | " << sb << endl;
        cout << "MATRIX: " << endl;
        for(int ia=0; ia<=l; ia++){
            for(int ib=0; ib<=l; ib++){
                cout << dp[ia][ib] << " ";
            }

            cout << endl;
        }
        cout << "MAXI: " << maxi << endl;
        cout << "A, B: " << a << " " << b << endl;
        
        if(maxi==0) return "";
        
        string lps = "";
        for(int i=maxi; i>0; i--){ //Traverse Diagonally
            lps+=sa[a-1];
            a--;
        }
        
        return lps;
        
    }
};

int main(){
    string sa = "aacabdkacaa";
    Solution newSol;
    cout << newSol.longestPalindrome(sa);

    return 0;
}