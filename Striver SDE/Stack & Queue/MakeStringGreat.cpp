// LeetCode - 1544. Make String Great.
// Given a string s of lower and upper case English letters.
// A good string is a string which doesn't have two adjacent characters s[i] and s[i + 1] where:

// 0 <= i <= s.length - 2
// s[i] is a lower-case letter and s[i + 1] is the same letter but in upper-case or vice-versa.
// To make the string good, you can choose two adjacent characters that make the string bad and remove them. You can keep doing this until the string becomes good.

// Return the string after making it good. The answer is guaranteed to be unique under the given constraints.
// Notice that an empty string is also good.


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string makeGood(string s) {
        int n = s.size();
        stack<char> stk;
        string good = "";
        
        for(int i=0; i<n; i++){
            if(!stk.empty() && abs(stk.top() - s[i]) == 32) stk.pop();
            else stk.push(s[i]);
        }
        
        while(!stk.empty()) {good += stk.top(); stk.pop();}
        reverse(good.begin(), good.end());
        
        return good;
    }
};