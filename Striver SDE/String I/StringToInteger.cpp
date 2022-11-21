// LeetCode - 8. String To Integer ATOI.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int sign = 1;
        double value = 0;
        bool read = false; //Reading has started.
        
        for(int i=0; i<n; i++){
            if(s[i] == ' '){ if(read) break; else continue; }
            if(s[i] == '+'){ 
                if(read) break;
                sign = 1; read = true;
                continue;
            }
            if(s[i] == '-'){
                if(read) break;
                sign = -1; read = true;
                continue;
            }
            
            if((s[i]-'0') < 0 || (s[i]-'0') > 9) break;
            read = true;
            value = value*10 + (s[i]-'0');
        }
        
        if((sign*value) > INT32_MAX) return INT32_MAX;
        if((sign*value) < INT32_MIN) return INT32_MIN;
        
        return (value*sign);
    }
};