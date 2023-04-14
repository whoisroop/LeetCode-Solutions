//GFG: City With the Smallest Number of Neighbors at a Threshold Distance. 
//Description: There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi , toi ,weighti]  represents a bidirectional and weighted edge between cities fromi and toi, and given the integer distance Threshold. You need to find out a city with the smallest number of cities that are reachable through some path and whose distance is at most Threshold Distance, If there are multiple such cities, our answer will be the city with the greatest number.

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxmax = 1e8;
    int findCity(int V, int m, vector<vector<int>>& edges, int distance){
        // Floyd Warshall
        vector<vector<int>> A(V, vector<int>(V, maxmax));
        for(int i=0; i<V; i++) A[i][i] = 0;
        
        for(auto &edge: edges){
             A[edge[0]][edge[1]] = edge[2];
             A[edge[1]][edge[0]] = edge[2];
        }
        
        for(int junction=0; junction<V; junction++){
            for(int i=0; i<V; i++){
                for(int j=0; j<V; j++){
                    A[i][j] = min(A[i][j], (A[i][junction] + A[junction][j]));
                }
            }
        }
        
        int nodeV = 0;
        int mincount = INT32_MAX;
        for(int i=0; i<V; i++){
            int neighbor = 0;
            for(int j=0; j<V; j++){
                if(A[i][j] <= distance) neighbor += 1;
            }
            
            if(neighbor <= mincount){
                nodeV = i;
                mincount = neighbor;
            }
        }
        
        return nodeV;
    }
};

int main(){
    Solution solve;
    
    return 0;
}