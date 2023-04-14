// GFG: KosaRaju Algorithm - Find Strongly Connected Components Of A Graph.
// Description - 
// Strongly connected component of a graph is a subset of a graph where there exists a path from any vertex a to vertex b and back in a directed graph.
// The graphs G and GT have the same SCC's. This means that vertices u and v are reachable from each other in G if and only if reachable from each other in GT. Where GT: Transponse Of G (Reverse Edge).
// First calculate the ordering of the graph G on the basis of finishing time, which denotes the order in which to process the SCC components in the GT.
// The basis of the concept is the component graph, it assumes a SCC as a vertex & has neighbor to other SCC if there exists a path in G.
// The component graph is DAG.
// Process the DAG using DFS!
// Taking transpose of G will restrict the DFS to visit all the vertex in a SCC. Given that we visited the vertex in the DECREASING ORDER of finishing time.
// The SCC visited first will not lead to any other SCC as the edges are reversed, therefore we're restricted in a SCC and all the vertex are visited. 

// LINK: https://www.personal.kent.edu/~rmuhamma/Algorithms/MyAlgorithms/GraphAlgor/strongComponent.htm

#include<bits/stdc++.h>
using namespace std;

class Solution{
private:
    // Not exactly topological sort: Ordering on the basis of finishing time.
    void topological(int nValue, vector<int> &visited, vector<int> &order, vector<vector<int>> &A){
        if(visited[nValue]) return;
        
        visited[nValue] = 1;
        for(int &neighbor: A[nValue]) topological(neighbor, visited, order, A);
        
        order.push_back(nValue);
        return;
    }
    
    void DFS(int nValue, vector<int> &visited, vector<vector<int>> &A){
        if(visited[nValue]) return;
        
        visited[nValue] = 1;
        // DFS PROCESS
        for(int &neighbor: A[nValue]) DFS(neighbor, visited, A);
        
        return;
    }
    
public:
    int kosaraju(int V, vector<vector<int>> &A){
        vector<int> toposort;
        vector<int> visited(V, 0);
        
        // Component Graph: DAG Find Topological Ordering
        for(int i=0; i<V; i++){
            if(visited[i]) continue;
            
            topological(i, visited, toposort, A);
        }
        
        reverse(toposort.begin(), toposort.end());
        
        // Transpose The Graph
        vector<vector<int>> AT(V);
        for(int i=0; i<V; i++){
            for(int &neighbor: A[i]) AT[neighbor].push_back(i);
        }
        
        int counter = 0;
        for(int &i: visited) i = 0;
        for(int i=0; i<V; i++){
            int nValue = toposort[i];
            if(visited[nValue]) continue;
            
            DFS(nValue, visited, AT);
            counter += 1;
        }
        
        return counter;
    }
};

int main(){
    Solution solve;
    
    return 0;
}