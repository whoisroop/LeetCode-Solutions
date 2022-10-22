// LeetCode - 692. Top K Frequent Words.
// Given an array of strings words and an integer k, return the k most frequent strings.
// Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.
#include<bits/stdc++.h>
using namespace std;

//The major takeaway is how to sort map!
//To sort a map on the basis of its value:
//The sort() inbuilt function only works for vectors, as a map is nothing but a vector of pairs, convert the map into vector namely vmap.
//vector<pair<string, int>> vmap(map.begin(), map.end());
//Write a compare (comparator) function to sort the individual element of the vmap i.e. pair<string, int>.
// string a, string b : a<b results true if string a is lexographically smaller than b.

bool compare(pair<string, int> &a, pair<string, int> &b){
        if(a.second!=b.second) return (a.second>b.second);
        else return (a.first<b.first);   //Lexicographically.
    }

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        unordered_map<string, int> mpp; //To map string with its frequency.
        
        for(const string &word: words) mpp[word]++;
        
        //Sorting Map using vector pair method.
        vector<pair<string, int>> vmap(mpp.begin(), mpp.end());

        sort(vmap.begin(), vmap.end(), compare);

        vector<string> solution;
        int count=0;
        for(auto i: vmap){
            solution.push_back(i.first);
            count++; if(count==k) break;
        }
        
        return solution;
    }
};