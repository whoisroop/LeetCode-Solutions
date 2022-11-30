// LeetCode - 28. Find the Index of the First Occurrence in a String.
// The program is implemented using Rabin Karp algorithm (String Hashing).
// Instead of using the hashing to calculate the total number of occurence of target string in source string. We break the algorithm at the first occurence of target string and return the starting index.

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    const int BASE = 31;
    const int MOD = 1000001;
public:
    int strStr(string source, string target) {
        int nS = source.size();
        int nT = target.size();
        
        int tHash = 0;  //Target Hash
        for(int i=0; i<nT; i++) tHash = ((1LL*tHash)*BASE + target[i])%MOD;
        
        int power = 1; //Power of ith element of the window.
        for(int i=0; i<(nT-1); i++) power = ((1LL*power)*BASE)%MOD;
        
        int i=0, j=0;
        int wHash = 0; //Window Hash
        while(j<nS){
            wHash = ((1LL*wHash)*BASE + source[j])%MOD;
            
            if((j-i+1) < nT) {j++; continue;}
            if(wHash == tHash){
                bool match = true;
                for(int p=i; p<=j; p++){
                    if(source[p] != target[p-i]){ match = false; break; }
                }
                
                if(match) return i;
            }
            
            wHash = (wHash - source[i]*power)%MOD;
            if(wHash < 0) wHash += MOD;
            i++; j++;
        }
        
        return -1;
    }
};