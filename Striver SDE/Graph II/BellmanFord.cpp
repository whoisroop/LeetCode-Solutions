//GFG: Bellman Ford.
//Description: 
// Approach:
// For a graph with V vertex, let the first vertex be 0 & last vertex be V-1. The total vertex: V. Max edge to exist between the first & the last is when all the other nodes are in between of the first & last, hence it'll consist of V - 1 edges. Which proves, in V - 1 iterations the value will propagate to its farthest node, guranteed.
// Doesn't matter in which order we process the edges. Random order each time will also do.

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int source) {
        vector<int> distance(V, 1e8);
        distance[source] = 0;
        
        for(int i=0; i<V-1; i++){
            for(auto &edge: edges){
                int u = edge[0], v = edge[1], weight = edge[2];
                if(distance[u] + weight < distance[v]) distance[v] = distance[u] + weight;
            }
        }
        
        for(auto &edge: edges){
            int u = edge[0], v = edge[1], weight = edge[2];
            if(distance[u] + weight < distance[v]) return {-1};
        }
        
        return distance;
    }
};

int main(){
    Solution solve;
    
    return 0;
}