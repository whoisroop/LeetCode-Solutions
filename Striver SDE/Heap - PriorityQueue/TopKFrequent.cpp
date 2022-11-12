// LeetCode - 347. Top K Frequent Elements.
// Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> &A, pair<int, int> &B){
    return (A.second > B.second);    
}

class Solution {
public:
    vector<int> topKFrequent(vector<int> &A, int k) {
        int n = A.size();
        map<int, int> fmap; //<Value, Frequency>
        
        for(int i=0; i<n; i++) fmap[A[i]]++;
        
        vector<pair<int, int>> vmap(fmap.begin(), fmap.end());
        sort(vmap.begin(), vmap.end(), compare);
        
        vector<int> result;
        for(int i=0; i<k; i++) result.push_back(vmap[i].first);
        
        return result;
    }
};