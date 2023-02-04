// LeetCode - 567. Permutation in String
// Description - 
// Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
// In other words, return true if one of s1's permutations is the substring of s2.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string t, string s) {
        int nt = t.size(); int ns = s.size();
        vector<int> given(26, 0);
        for(int i=0; i<nt; i++) given[(t[i]-'a')] += 1;

        vector<int> window(26, 0);
        int i=0, j=0;
        while(j<ns){
            window[(s[j] - 'a')] += 1;
            
            if((j - i + 1) < nt){ j += 1; continue; }

            if(window == given) return true;
            // cout << "WINDOW: " << i << " - " << j << endl;
            // for(int i: window) cout << i << " ";
            // cout << endl;
            window[(s[i] - 'a')] -= 1;
            i += 1; j += 1;
        }

        return false;
    }
};

int main(){
    Solution solve;
    
    return 0;
}