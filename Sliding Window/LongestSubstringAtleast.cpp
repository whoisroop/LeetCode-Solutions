// LeetCode - 395. Longest Substring With Atleast K Repeating Characters.
// Given a string s and an integer k, return the length of the longest substring of s such that the frequency of each character in this substring is greater than or equal to k.

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// The problem of the question lies in the "ATLEAST" part : When to increase window & when to decrease?
// In all the sliding window problems we determine whether to increase to decrease the window on the basis of unique characters in the window and frequency of the characters.
// Hence, Here we'll calculate the max window size of the window: containing 1 unique, 2 unique, ... , N unique elements AND for each case find those windows where frequency of all those unique characters in the window must be equal to K.
// Explanation - 
// Find a windows containing X unique characters. (totalU)
// After finding such window check if the frequency of all X characters are greater than or equal to K. (atleastK)
// If it is, store the value as it will be candidate for answer.

class Solution{
private: 
    int fx(string &s, int k, int totalU){   //totalU : Total Unique
        int n = s.size();
        int i=0, j=0;

        unordered_map<char, int> mpp;  //Character Frequency Map Of The Window.
        int windowU = 0;    //Unique Characters In Window.
        int atleastK = 0;   //Characters In Window With Atleast k Occurences.
        int maxi = 0;

        while(j<n){
            if(mpp.find(s[j]) == mpp.end()) windowU++;    //If element in not already in the window. Increase atleastK of unique elements.
            
            mpp[s[j]]++; if(mpp[s[j]] == k) atleastK++;  //If the count of element >= k : Increase atleastK variable.
            
            //If the count of unique element exceeds the limit, decrease window. Else increase window.
            if(windowU > totalU){
                while(windowU > totalU){
                    if(mpp[s[i]] == k) atleastK--;  //If the frequency of character is k, decrease the atleastK.
                    mpp[s[i]]--; 
                    
                    if(mpp[s[i]]==0){ 
                        windowU--; 
                        mpp.erase(mpp.find(s[i])); 
                    }

                    i++;
                }
            }
            
            if(atleastK == windowU) maxi = max(maxi, (j-i+1)); //If all the elements in the window occurs atleast k times.
            j++;
        }

        return maxi;
    }

public:
    int findLongest(string &s, int k){
        int n = s.size();
        if(k>n) return 0;

        //Find Total Number Of Unique Elements:
        vector<int> mpp(26, 0);
        int unique = 0;
        for(const char &c: s){
            if(mpp[c-'a']==0) unique++;
            mpp[c-'a']++;
        }

        int maxi = 0;
        for(int i=1; i<=unique; i++){
            maxi = max(maxi, fx(s, k, i));
        }

        return maxi;
    }
};

int main(){
    string s = "aaabb";
    int k = 3;
    Solution find;
    cout << find.findLongest(s, k);
    return 0;
}