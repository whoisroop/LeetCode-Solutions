// LeetCode - 287. Find Duplicate Element.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int> &array) {
        int n = array.size();
        bitset<100001> bset;
        
        for(const int &i: array){
            if(bset[i]==1) return i;
            bset[i]=1;
        }
        
        return 0;
    }
};