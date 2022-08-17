//LeetCode - 76. Minimum Window Substring
// Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution{
public:
    string findMin(string &s, string &t){
        unordered_map<char, int> mpp;
        for(const char &c: t) mpp[c]++; //Create frequency map of t.

        int i=0; int j=0;
        int mini = INT32_MAX;
        int n = s.size();
        int distinct = mpp.size();  //Number of distinct letters.
        string sol;
        while(j<n){
            //If the jth letter of s is present in t.
            if(mpp.find(s[j])!=mpp.end()){
                mpp[s[j]]--;
                if(mpp[s[j]]==0) distinct--;
            } 

            if(distinct==0){
                if(mini>(j-i+1)){
                    mini = (j-i+1);
                    sol = s.substr(i, (j-i+1));
                }

                while(distinct==0){
                    if(mpp.find(s[i]) != mpp.end()){
                        mpp[s[i]]++;
                        if(mpp[s[i]]==1) distinct++;
                    }
                    i++;

                    if(distinct==0){
                        if(mini>(j-i+1)){
                            mini = (j-i+1);
                            sol = s.substr(i, (j-i+1));
                        }
                    }
                }

                j++;
            }
            else j++;
        }

        return sol;
    }

};

int main(){
    string s = "ADOBECODEBANC";
    string t = "ABC";
    Solution find;
    cout << find.findMin(s, t) << endl;

    return 0;
}