// GFG: Number of Good Components. 
// Description: 
// Given an undirected graph with V vertices(numbered from 1 to V) and E edges. 
// Find the number of good components in the graph.
// A component of the graph is good if and only if the component is a fully connected component.
// Note: A fully connected component is a subgraph of a given graph such that there's an edge between every pair of vertices in a component, the given graph can be a disconnected graph. Consider the adjacency list from vertices 1.

// Approach:
// Perform DFS & find a component of the graph, the DFS traversal contains nodes in the component.
// The nodes in DFS are part of the component & a path exists between the components that connects them all, no other nodes are reachable from the component nodes apart from those of DFS traversal. 
// Check if all the nodes are connected to all the nodes of the component i.e. Let the component have V vertices, therefore the (A[V].size() == V-1) : If all the vertices follow the condition it is a good component. 

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    void DFS(int nV, vector<int> &visited, vector<int> &traversal, vector<vector<int>> &A){
        visited[nV] = 1;
        traversal.push_back(nV);
        
        for(auto &neighbor: A[nV]){
            if(visited[neighbor] == 0) DFS(neighbor, visited, traversal, A);
        }
        
        return;
    }
    
public:
    int findNumberOfGoodComponent(int V, vector<vector<int>>& A) {
        int counter = 0;
        vector<int> visited(V+1, 0);
        for(int nV=1; nV<=V; nV++){
            if(visited[nV] == 1) continue;
            
            vector<int> traversal;
            DFS(nV, visited, traversal, A);
            int totalV = traversal.size();
            
            counter += 1;
            for(int &nV: traversal) if(A[nV].size() != (totalV - 1)){ counter -= 1; break; }
            
        }
        
        return counter;
    }
};

int main(){
    Solution solve;
    
    return 0;
}