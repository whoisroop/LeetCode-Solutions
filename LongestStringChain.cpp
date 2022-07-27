//Longest Increasing Subsequence: REFER
#include<bits/stdc++.h>
using namespace std;

bool comp(string &sa, string &sb){
    return sa.size() < sb.size();
}

class Solution{
private:
    bool compare(string &sa, string &sb){ //String A - String B : 1 Character
        int la = sa.size();
        int lb = sb.size();

        if((la-lb)!=1)    return false;

        int count = 0;
        int ia=0, ib=0;
        while(ia<la && ib<lb){
            if(sa[ia]!=sb[ib]){
                count++;
                ia++;
            }
            else{
                ia++;
                ib++;
            }
        }

        if(count==1 || ia == (la-1))    return true;
        else    return false;
        
    }

public:
    int stringChain(vector<string> &str){
        int n = str.size()-1;
        if(n==0)    return 1;
        sort(str.begin(), str.end(), comp);
        
        for(auto i: str)    cout << i << " ";
        cout << endl;

        vector<int> dp(n+1, 1); //To store the max size of subsequence

        int maxi = 1;
        for(int i=1; i<=n; i++){
            for(int pi=0; pi<i; pi++){
                if(compare(str[i], str[pi]) && (dp[pi]+1>dp[i])){
                    dp[i] = dp[pi]+1;
                    maxi = max(maxi, dp[i]);
                }
            }
        }

        return maxi;
    }

};

int main(){
    vector<string> str = {"xbc","pcxbcf","xb","cxbc","pcxbc"};
    Solution newSol;
    cout << newSol.stringChain(str);

    return 0;
}