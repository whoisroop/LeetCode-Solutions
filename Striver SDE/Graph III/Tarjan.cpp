// GFG - Bridge Edge Of A Graph
// Description - 
// TARJAN's ALGORITHM

// Perfom DFS and store the order at which the nodes are traversed.
// Maintain a vector that maintains alternate path to a node if possible to reach before the parent node.
// (nV:5 Index:0) --> (nV:7 Index:1) --> (nV:3 Index:2)
//      ^                                      |
//      |______________________________________|
// If by some means, there is a way or path for the node to reach to a node previous (traversed previously in order of traversal) to the parent node, means by breaking the edge between the parent & the current node the graph cannot be broken into two parts.
// Node Value :     {5, 7, 3}
// The indexing :   {0, 1, 2}
// Alternate Path : {0, 1, 2}

// DFS -
// Parent 5, nV 5
// Parent 5, nV 7
// Parent 7, nV 3
// All the neighbors of nV 3 are visited, now check if there exists any path to reach a node previously traversed in order of indexing path from the parent node.
// YES: path[3] = min(path[3], path[5]) = min(2, 0) = 0.
// COMPARE PARENT & NODE: if path[NODE] < index[parent] - The edge is a not a bridge edge.
// 0 -> 1 -> 2 for a bridge edge to exists between 1 & 2 for example, 2 shouldnot be connected to the left or previously traversed nodes apart from parent in anyways. If there exists a path from 2 to 0 or 1 apart from the parent 1 -> 2 node, breaking the edge, the graph will still stay connected. 

#include<bits/stdc++.h>
using namespace std;

class Solution{
private:
    void DFS(int nV, int parent, vector<int> A[], vector<int> &visited, vector<int> &index, vector<int> &apath, int counter, vector<vector<int>> &bridge){
        if(visited[nV]) return;
        
        visited[nV] = 1;
        index[nV] = counter;    counter += 1;
        apath[nV] = index[nV];
        
        bool aVisited = true;
        for(int &neighbor: A[nV]){
            if(neighbor == parent) continue;
            
            DFS(neighbor, nV, A, visited, index, apath, counter, bridge);
            apath[nV] = min(apath[nV], apath[neighbor]);
        }
        
        if(apath[nV] > index[parent]){
            if(parent <= nV) bridge.push_back({parent, nV});
            else bridge.push_back({nV, parent});
        }
        
        return;
    }

public:
    int isBridge(int V, vector<int> A[], int X, int Y) {
        vector<int> index(V, 0), apath(V, 0), visited(V, 0);
        vector<vector<int>> bridge;

        for(int i=0; i<V; i++){
            if(visited[i] == 1) continue;
            
            DFS(i, i, A, visited, index, apath, 0, bridge);
        }
        
        vector<int> check;  if(X <= Y) check = {X, Y}; else check = {Y, X};
        for(auto &edge: bridge) if(edge == check) return 1;
        
        return 0;
    }
};

int main(){
    Solution solve;
    
    return 0;
}