#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution{
public:
    //Instead of storing the length store the ASCII value in the dp array.
    int minASCII(string &sa, string &sb){
        int la = sa.size(); int lb = sb.size();
        
        vector<vector<int>> dp(la+1, vector<int>(lb+1, 0));
        
        //Instead of storing the size: store ASCII value.
        for(int ia=0; ia<=la; ia++){
            for(int ib=0; ib<=lb; ib++){
                if(ia==0 || ib==0) continue;
                int longest=0;
                if(sa[ia-1]==sb[ib-1]) longest = (int)sa[ia-1] + dp[ia-1][ib-1];
                else{
                    longest = max( dp[ia][ib-1], dp[ia-1][ib] );
                }
                
                dp[ia][ib] = longest;
            }
        }

        int sum = 0;
        for(const char &c: sa) sum += (int)c;
        for(const char &c: sb) sum += (int)c;

        return (sum - 2*(dp[la][lb]));
        
    }

    //Brute Approach:
    //Calculate DP array & retrace the path of LCS such that the ASCII sum is greater.

    //Retracing The Path: Such that the ASCII sum is maximum of the LCS.
    string find(int i, int j, string &sa, string &sb, vector<vector<int>> &dp, vector<vector<string>> &dpp){
        if(i==0 || j==0) return "";

        if(dpp[i][j]!="-1") return dpp[i][j];
        string lcs = "";
        if(sa[i-1]==sb[j-1]){
            lcs += sa[i-1] + find(i-1, j-1, sa, sb, dp, dpp);
        }
        else{
            if(dp[i-1][j]==dp[i][j-1]){
                string a = find(i, j-1, sa, sb, dp, dpp);
                string b = find(i-1, j, sa, sb, dp, dpp);
                int asciiA=0, asciiB=0;
                for(const char &c: a) asciiA += (int)c;
                for(const char &c: b) asciiB += (int)c;
                if(asciiA > asciiB) lcs+=a;
                else lcs+=b;
            }
            else{
                if(dp[i-1][j]>dp[i][j-1]) lcs = find(i-1, j, sa, sb, dp, dpp);
                else lcs = find(i, j-1, sa, sb, dp, dpp);
            }
        }

        return dpp[i][j] = lcs;
    }

    //Calculating DP array & managing the frequency of letters using unordered map.

    int findMinASCII(string &sa, string &sb){
        int la = sa.size(); int lb = sb.size();
        unordered_map<char, int> mppA;
        unordered_map<char, int> mppB;
        
        for(const char &c: sa) mppA[c]++;
        for(const char &c: sb) mppB[c]++;
        
        vector<vector<int>> dp(la+1, vector<int>(lb+1, 0));
        
        for(int ia=0; ia<=la; ia++){
            for(int ib=0; ib<=lb; ib++){
                if(ia==0 || ib==0) continue;
                int longest=0;
                if(sa[ia-1]==sb[ib-1]) longest = 1 + dp[ia-1][ib-1];
                else{
                    longest = max( dp[ia][ib-1], dp[ia-1][ib] );
                }
                
                dp[ia][ib] = longest;
            }
        }
        
        cout << "MAP A || BEFORE : " << endl;
        for(const auto &i: mppA) cout << i.first << " - " << i.second << endl;
        cout << "MAP B || BEFORE : " << endl;
        for(const auto &i: mppB) cout << i.first << " - " << i.second << endl;
        
        vector<vector<string>> dpp(la+1, vector<string>(lb+1, "-1"));
        string lcs = "";
        lcs = find(la, lb, sa, sb, dp, dpp);

        for(const char &c: lcs){
            mppA[c]--;
            mppB[c]--;
        }

        cout << "MAP A || AFTER : " << endl;
        for(const auto &i: mppA) cout << i.first << " - " << i.second << endl;
        cout << "MAP B || AFTER : " << endl;
        for(const auto &i: mppB) cout << i.first << " - " << i.second << endl;

        cout << "LCS: " << lcs << endl;

        int sum=0;
        for(const auto &i: mppA) sum += ((int)i.first)*i.second;
        for(const auto &i: mppB) sum += ((int)i.first)*i.second;
        
        return sum;
    }
};

int main(){
    string sa = "delete";
    string sb = "leet";
    Solution find;
    cout << find.minASCII(sa, sb);
    return 0;
}