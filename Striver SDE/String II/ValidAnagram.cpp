// LeetCode - 242. Valid Anagram.
// Given two strings s and t, return true if t is an anagram of s, and false otherwise.
// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string source, string target) {
        //Since they're anagrams. Sorting them would give the same result!
        sort(source.begin(), source.end());
        sort(target.begin(), target.end());
        return (source==target);
    }
};

//Alternate Solution: Compare the frequency of characters.
// class Solution {
// public:
//     bool isAnagram(string source, string target) {
//         vector<int> freq(26, 0);
//         for(char &i: source) freq[(i-'a')]++;
//         for(char &i: target) freq[(i-'a')]--;
//         for(int &i: freq){
//             if(i!=0)    return false;
//         }
//         return true;
//     }
// };