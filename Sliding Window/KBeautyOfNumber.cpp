//The k-beauty of an integer num is defined as the number of substrings of num when it is read as a string that meet the following conditions:
//It has a length of k.
// It is a divisor of num.
// Given integers num and k, return the k-beauty of num.

// Note:
// Leading zeros are allowed.
// 0 is not a divisor of any value.
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int divisorSubstrings(int num, int window) {
        int i=0; int j=0;
        string s = to_string(num);
        int n = s.size();
        
        int count = 0;
        string seq = "";
        while(j<n){
            seq += s[j];
            
            if((j-i+1)<window) j++;
            else{
                int value = stoi(seq);
                if(value!=0 && num%value==0) count++;
                
                seq.erase(seq.begin());
                i++; j++;
            }
        }
        
        return count;
    }
};

int main(){
    int x = 4300043;
    Solution find;
    cout << find.divisorSubstrings(x,2);
    return 0;
}