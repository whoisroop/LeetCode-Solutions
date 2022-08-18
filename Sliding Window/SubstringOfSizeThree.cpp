//LeetCode - 1876 Substrings of Size Three with Distinct Characters
//A string is good if there are no repeated characters.
//Given a string s​​​​​, return the number of good substrings of length three in s​​​​​​.
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int count(string &s) {
        int i=0; int j=0;
        unordered_map<char, int> mpp;
        int n = s.size();
        int count=0;    //Answer
        int letters = 0;  //Letters
        bool isRepeating = false;
        char repeat;
        while(j<n){
            mpp[s[j]]++; letters++;
            
            if((j-i+1)<3) j++;
            else{
                if(mpp.size()==letters) count++;
                
                mpp[s[i]]--; letters--;
                if(mpp[s[i]]==0) mpp.erase(mpp.find(s[i]));
                i++; j++;
            }
        }
        
        return count;
    }
};

int main(){
    string s = "aababcabc";
    Solution find;
    cout << find.count(s);
    return 0;
}