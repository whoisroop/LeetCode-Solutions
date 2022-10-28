// LeetCode - 3. Longest Substring With No Repeating Character.
// SLIDING WINDOW.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string &s) {
        int n = s.size();
        unordered_map<char, int> fmap;
        
        int i=0, j=0;
        int maxl = 0;
        while(j<n){
            fmap[s[j]]++;
            
            if(fmap[s[j]]>1){
                while(fmap[s[j]]>1){
                    fmap[s[i]]--; i++;
                }
            }
            
            maxl = max(maxl, (j-i+1));
            j++;
        }
        
        return maxl;
    }
};
