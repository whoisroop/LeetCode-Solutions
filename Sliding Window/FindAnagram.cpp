//Leetcode - 438 Find All Anagrams In A String
#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    //Return all the starting indexes of anagrams of string p in string s.
    vector<int> findAnagrams(string s, string p){
        unordered_map<char, int> mpp;
        for(const char &c: p)   mpp[c]++;

        vector<int> index;
        int i=0; int j=0;
        int window = p.size();
        int li = s.size()-1;
        int count = mpp.size();    //Total Distinct Letters
        while(j<=li){
            if((j-i+1)<window){
                if(mpp.find(s[j])!=mpp.end()){  //The character is present.
                    mpp[s[j]]--;    //Decrement count of that letter.
                    if(mpp[s[j]]==0) count--;   //If frequency of the letter is zero the number of distinct letters decreases.
                }

                j++;
            }
            else{
                if(mpp.find(s[j])!=mpp.end()){
                    mpp[s[j]]--;
                    if(mpp[s[j]]==0) count--;
                }

                if(count==0) index.push_back(i);    //The window is set & there's no distinct letter left: Anagram!

                if(mpp.find(s[i])!=mpp.end()){  //If the ith character is part of anagram then increase its frequency for next window set.
                    mpp[s[i]]++;
                    if(mpp[s[i]]==1)    count++;
                }

                i++; j++; 
            }
        }

        // for(int i: index) cout << i << " ";
        return index;
    }

    // vector<int> findAnagrams(string s, string p) {
    //     int s_len = s.length();
    //     int p_len = p.length();
        
    //     if(s.size() < p.size()) return {};
        
    //     vector<int> freq_p(26,0);
    //     vector<int> window(26,0);
        
    //     //first window
    //     for(int i=0;i<p_len;i++){
    //         freq_p[p[i]-'a']++;
    //         window[s[i]-'a']++;
    //     }
        
    //     vector<int> ans;
    //     if(freq_p == window) ans.push_back(0);
        
    //     for(int i=p_len;i<s_len;i++){
    //         window[s[i-p_len] - 'a']--;
    //         window[s[i] - 'a']++;
            
    //         if(freq_p == window) ans.push_back(i-p_len+1);
    //     }
    //     return ans;
    // }
};

int main(){
    string s = "abab";
    string p = "ab";
    Solution find;
    find.findAnagrams(s, p);
    return 0;
}