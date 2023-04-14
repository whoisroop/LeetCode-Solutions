//GFG: Find the minimum distance path from source to a vertex.
//Description: 

// Approach: Remember the previous or parent node, so that the minimum distance of the node can be traced back to the source.

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> shortestPath(int D, int M, vector<vector<int>>& edges) {
        int source = 1;
        int V = D + 1; //D is the destination node.
        vector<vector<pair<int, int>>> A(V);
        for(auto edge: edges){
            A[edge[0]].push_back({edge[1], edge[2]});
            A[edge[1]].push_back({edge[0], edge[2]});
        }
        
        vector<int> distance(V, INT32_MAX);
        vector<int> parent(V, -1);
        
        distance[source] = 0;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, source});
        
        while(!pq.empty()){
            int nValue = pq.top().second;
            int total = pq.top().first;
            pq.pop();
            
            for(auto &neighbor: A[nValue]){
                int neighborV = neighbor.first;
                int weight = neighbor.second;
                
                if(total + weight < distance[neighborV]){
                    distance[neighborV] = total + weight;
                    parent[neighborV] = nValue;
                    pq.push({distance[neighborV], neighborV});
                }
            }
        }
        
        for(int &i: distance) if(i == INT32_MAX) i = -1;
        
        if(distance[V - 1] == -1) return {-1};
        
        int nodeV = V-1;    //Destination
        vector<int> path;
        while(parent[nodeV] != -1){
            path.push_back(nodeV);
            nodeV = parent[nodeV];
        } path.push_back(nodeV);
        
        reverse(path.begin(), path.end());
        return path;
    }
};

int main(){
    Solution solve;
    
    return 0;
}