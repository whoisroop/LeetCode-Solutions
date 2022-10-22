// LeetCode - 76. Minimum Window Substring.
// Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string ""

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    string find(string &s, int k, unordered_map<char, int> fmap){
        int n = s.size();
        cout << "FMAP SIZE:  " << fmap.size() << " + " << k << endl;
        for(auto &i: fmap) cout << i.first << " - " << i.second << endl;

        int tunique = fmap.size() + k;

        unordered_map<char, int> wmap;  //Window Map
        int i=0, j=0;

        int contained=0;    //Contained Elements From FMap in WMaps.

        int start, end;
        int mWindow = 1e9; bool isFound = false;
        while(j<n){
            wmap[s[j]]++;   if(wmap[s[j]] == fmap[s[j]]) contained++;

            cout << endl;
            cout << i << " & " << j << " | Contained: " << contained << endl;
            cout << "WINDOW: " << endl;
            for(auto &i: wmap) cout << i.first << " - " << i.second << endl;

            cout << "WINDOW SIZE: " << wmap.size() << " & TOTAL UNIQUE: " << tunique << endl;
            if(wmap.size() > tunique){
                while(wmap.size() > tunique){
                    if(wmap[s[i]] == fmap[s[i]]) contained--;
                    wmap[s[i]]--;   if(wmap[s[i]]==0) wmap.erase(wmap.find(s[i]));
                    i++;
                }
                
                cout << " *SHRINK!* " << endl;
                cout << i << " & " << j << " | Contained: " << contained << endl;
                cout << "WINDOW: " << endl;
                for(auto &i: wmap) cout << i.first << " - " << i.second << endl;
            }

            if(contained + k == tunique){
                cout << "XXXXXXXXXXXXXXXXX" << endl;
                if((j-i+1) < mWindow){
                    start = i; end = j;
                    mWindow = (j-i+1);
                }
                cout << "START: " << i << " & END: " << end << " | " << mWindow << endl;
                isFound = true;
            }

            j++;
        }

        if(isFound) return s.substr(start, mWindow);
        else return s;
    }

    string findSubstring(string &s, string &t){
        int ls = s.size();
        int lt = t.size();

        unordered_map<char, int> fmap;  //Frequency Map For T String
        for(const char &c: t) fmap[c]++;
        
        unordered_map<char, int> smap;
        for(const char &c: s) smap[c]++;

        int unique = smap.size();

        for(const char &c: t) if(fmap[c] > smap[c]) return "";

        string mini = s; string substring = "";
        for(int i=0; i<=unique; i++){
            substring = find(s, i, fmap);
            if(substring.length() < mini.length()) mini = substring;
            cout << "SUBSTRING FOR: i = " << i << " : " << substring << " | " << mini << endl;
        }

        return mini;

    }
};

int main(){
    string s = "bba";
    string t = "ab";
    Solution find;
    cout << find.findSubstring(s, t);
    return 0;
}