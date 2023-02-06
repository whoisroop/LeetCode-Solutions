// LeetCode - 49. Group Anagrams
// Description - 
// Given an array of strings strs, group the anagrams together. You can return the answer in any order.
// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

#include<bits/stdc++.h>
using namespace std;

class Solution{
private:

public:
    vector<vector<string>> groupAnagrams(vector<string> &word) {
        int n = word.size();
        vector<vector<string>> solution;

        unordered_map<string, vector<string>> amap; //Anagram Map
        // Compare by sorting:
        // amap[aet] - eat, ate, tea

        for(int i=0; i<n; i++){
            string st = word[i];
            sort(st.begin(), st.end());
            amap[st].push_back(word[i]);
        }

        for(auto &i: amap) solution.push_back(i.second);

        return solution;
    }
};

int main(){
    Solution solve;
    
    return 0;
}