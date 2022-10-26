// Largest SUB-ARRAY with zero sum.

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        unordered_map<int, int> imap;   //Map SUB-ARRAY sum with index.
        int sum = 0; int maxi = 0;
        
        imap[0] = 0;
        for(int i=0; i<n; i++){
            sum += A[i];
            
            if(imap.find(sum) != imap.end()){
                maxi = max(maxi, ((i+1) - imap[sum]));
            }
            else imap[sum] = i+1;
        }
        
        return maxi;
    }
};