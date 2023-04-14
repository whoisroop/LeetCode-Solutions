//GFG: Number of Ways to Arrive at Destination. 
//Description: Find the number of paths from vertex 0 to V-1 having the shortest distance.
//Approach: Dijkshtra's Algorithm.
//To find the number of ways of reaching vertex X, find number of ways of reaching vertex (neighbor) from where we reached X, sum them all.
// A
//    \ 
// B - X
//    /
// C
// Number of ways of reaching X = Number Of Ways of Reaching A + B + C.

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int MOD = 1e9 + 7;
    int countPaths(int V, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> A(V);
        for(auto edge: roads){
            A[edge[0]].push_back({edge[1], edge[2]});
            A[edge[1]].push_back({edge[0], edge[2]});
        }
        
        vector<int> distance(V, INT32_MAX);
        vector<int> ways(V, 0);
        
        distance[0] = 0;
        ways[0] = 1;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, 0}); //Node Distance
        while(!q.empty()){
            auto top = q.top(); q.pop();
            int nValue = top.first;
            int total = top.second;
            
            for(auto &next: A[nValue]){
                int neighbor = next.first, weight = next.second;
                if(1LL*total + weight == distance[neighbor]) ways[neighbor] = (1LL*ways[neighbor] + ways[nValue])%MOD;
                
                if(1LL*total + weight < distance[neighbor]){
                    q.push({neighbor, total+weight});
                    ways[neighbor] = ways[nValue];
                    distance[neighbor] = (1LL*total + weight)%MOD;
                }
            }
        }
        
        return ways[V-1];
    }
};

int main(){
    Solution solve;
    
    return 0;
}