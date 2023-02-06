// LeetCode - 1647. Minimum Deletions to Make Character Frequencies Unique.

// A string s is called good if there are no two different characters in s that have the same frequency.
// Given a string s, return the minimum number of characters you need to delete to make s good.
// The frequency of a character in a string is the number of times it appears in the string. For example, in the string "aab", the frequency of 'a' is 2, while the frequency of 'b' is 1.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDeletions(string s) {
        int n = s.size();
        unordered_map<char, int> fmap;
        for(char &c: s) fmap[c]++;

        // Create a vector that shows which frequency is repeated how many times:
        // Example: aabcc
        // 0 1 2 1 : Frequency
        // 0 1 2 3 : Index
        // Use a stack to keep track of the index that has zero frequency, and shift the elements from the one with the frequency greater than one (As Frequency Of Lettes: UNIQUE) to the one where there's 0 in the vector.
        vector<int> ff(n+1, 0); //Frequency Of Frequency
        for(auto &i: fmap) ff[i.second]++;

        stack<int> stk;
        int count = 0;
        for(int i=0; i<=n; i++){
            if(ff[i] == 0) stk.push(i);

            while(ff[i] > 1){
                if(stk.empty()){
                    count += ((ff[i]-1)*i);
                    ff[i] = 1;
                }
                else{
                    count += (i - stk.top());
                    ff[i]--;
                    ff[stk.top()]++;
                    stk.pop();
                }
            }
        }

        return count;
    }
};