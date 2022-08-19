//LeetCode - 1297. Maximum occurences of a substring.
//Given a string s, return the maximum number of ocurrences of any substring under the following rules:
// 1. The number of unique characters in the substring must be less than or equal to maxLetters.
// 2. The substring size must be between minSize and maxSize inclusive.
#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int maxFind(string &s, int maxLetters, int window){
        int i=0; int j=0;
        unordered_map<string, int> strings; //To Store Strings
        unordered_map<char, int> mpp;   //To Store Frequency
        int n = s.size();
        //Instead use substring to find the window string when the condition matches! Reduces time complexity.
        string seq = ""; 
        while(j<n){
            seq += s[j];
            mpp[s[j]]++;

            if((j-i+1)<window) j++;
            else if((j-i+1)==window){
                if(mpp.size()<=maxLetters) strings[seq]++;

                //Decrease window.
                mpp[s[i]]--; if(mpp[s[i]]==0) mpp.erase(mpp.find(s[i])); 
                seq.erase(seq.begin()); //O(WindowSize)
                
                i++; j++;
            }
        }
        
        int maxi=0;
        for(const auto &i: strings){
            if(i.second > maxi) maxi = i.second;
        }
        return maxi;
    }
    
    int maxFreq(string s, int maxLetters, int minSize, int maxSize){
        //int maxi=0;
        // for(int i=minSize; i<=maxSize; i++){
        //     maxi = max(maxi, maxFind(s, maxLetters, i));
        // }
        //return maxi;

        //Just find the maximum occurences using the minimum window size, as the greater window size gets the part of smaller window sized substrings repeats. In best case the max occurences of min window = max window.
        return maxFind(s, maxLetters, minSize);
    }
};

int main(){
    string s = "abcabababacabcabc";
    Solution find;
    cout << find.maxFreq(s,3,3,10);
    return 0;
}