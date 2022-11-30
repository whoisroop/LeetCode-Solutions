// LeetCode - 38. Count & Say.
// To determine how you "say" a digit string, split it into the minimal number of substrings such that each substring contains exactly one unique digit. Then for each substring, say the number of digits, then say the digit. Finally, concatenate every said digit.

// For example, the saying and conversion for digit string "3322251":
// The next in sequence will be: 23 32 15 11

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        int counter = 0;
        string value = "";
        
        string say = "1";
        for(int i=0; i<(n-1); i++){
            string next = "";
            
            counter = 0;
            int size = say.size();
            for(int j=0; j<size; j++){
                if(j==0 || say[j]==say[j-1]){ value = say[j]; counter++; }
                else{
                    next += to_string(counter); next += value;
                    value = say[j]; counter = 1;
                }   
            } next += to_string(counter); next += value;
            
            say = next;
        }
        
        return say;
    }
};