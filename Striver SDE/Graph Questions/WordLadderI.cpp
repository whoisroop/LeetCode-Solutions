// GFG - Word Ladder I
// Description - Given two distinct words startWord and targetWord, and a list denoting wordList of unique words of equal lengths. Find the length of the shortest transformation sequence from startWord to targetWord.

// Keep the following conditions in mind:

// A word can only consist of lowercase characters.
// Only one letter can be changed in each transformation.
// Each transformed word must exist in the wordList including the targetWord.
// startWord may or may not be part of the wordList 

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxmax = 1e6;
    
    bool onestep(string given, string check){
        int n = given.size();
        int counter = 0;
        for(int i=0; i<n; i++){
            if(given[i] != check[i]) counter += 1;
            if(counter > 1) return false;
        }
        
        return true;
    }
    
    // Dijkshtra's
    int shortest(vector<vector<int>> &A, int snode, int tnode){
        int V = A.size();
        vector<vector<int>> distance = A;
        queue<pair<int, int>> q;
        q.push({0, snode});
        
        vector<int> visited(V, 0);
        while(!q.empty()){
            auto top = q.front(); q.pop();
            int total = top.first;
            int nValue = top.second;
            
            if(nValue == tnode){
                int minV = (total + 1);
                return minV;
            }
            
            for(int neighbor=0; neighbor<V; neighbor++){
                if(A[nValue][neighbor] != maxmax && !visited[neighbor]){
                    q.push({total+1, neighbor});
                    visited[neighbor] = 1;
                }
            }
        }
        
        return maxmax;
    }
    
    int wordLadderLength(string sword, string tword, vector<string>& wordList) {
        int V = wordList.size();
        unordered_map<string, int> nmap;    //Node Map: NAME - NUMBER
        for(int i=0; i<V; i++) nmap[wordList[i]] = i;
        
        vector<vector<int>> A(V, vector<int>(V, maxmax));    //Adjacency Matrix
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                if(i == j) A[i][j] = 0;
                if(onestep(wordList[i], wordList[j])) A[i][j] = 1;
            }
        }
        
        int snode = -1;
        int tnode = -1;
        int minV = 0;
        
        stack<int> stk;
        if(nmap.find(sword) == nmap.end()){
            for(int i=0; i<V; i++) if(onestep(sword, wordList[i])){ stk.push(i); snode = i; }
            minV = 1;
        }
        else snode = nmap[sword];
        
        if(nmap.find(tword) != nmap.end()) tnode = nmap[tword];
        
        if(snode == -1 || tnode == -1) return 0;
        
        // Dijkshtra's:
        if(!stk.empty()){
            int minimum = maxmax;
            while(!stk.empty()){
                snode = stk.top(); stk.pop();
                minimum = min(minimum, shortest(A, snode, tnode));
            }
            
            return (minimum >= maxmax) ? 0 : (minimum + 1);
        }
        
        int minimum = shortest(A, snode, tnode);
        return  (minimum >= maxmax) ? 0 : (minimum);;
    }
};

int main(){
    Solution solve;
    
    return 0;
}