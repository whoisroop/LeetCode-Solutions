// LeetCode - 5. Longest Palindromic Substring.
// String Matching Question.

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int find(int ia, int ib, string &sa, string &sb){
        if(ia<0 || ib<0) return 0;

        if(sa[ia] == sb[ib]){
            int pathA = 1 + find(ia-1, ib-1, sa, sb);
            return pathA;
        }
        else{
            int pathA = 0 + find(ia-1, ib, sa, sb);
            int pathB = 0 + find(ia, ib-1, sa, sb);
            return max(pathA, pathB);
        }
    }

    string longestPalindrome(string &sa){
        int n = sa.size();
        string sb = sa; reverse(sb.begin(), sb.end());
    }
};