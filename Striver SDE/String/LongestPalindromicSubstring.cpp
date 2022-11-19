// LeetCode - 5. Longest Palindromic Substring.
// String Matching Question.

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int find(int index, string &sa, string &sb){
        if(index < 0) return 0;
    }

    string longestPalindrome(string &sa){
        int n = sa.size();
        string sb = sa; reverse(sb.begin(), sb.end());
    }
};