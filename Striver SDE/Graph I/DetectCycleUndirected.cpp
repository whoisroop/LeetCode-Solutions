// GFG - Detect Cycle In Undirected Graph.
// Description - Given an undirected graph with V vertices and E edges, check whether it contains any cycle or not. Graph is in the form of adjacency list where adj[i] contains all the nodes ith node is having edge with.

#include<bits/stdc++.h>
using namespace std;

class DFS {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> A[]) {
        // Perform DFS To Find Cycle:
        if(V == 0) return false;
        
        stack<int> stk;
        bitset<100001> visited;
        
        for(int vN = 0; vN < V; vN++){
            if(visited[vN] == 1) continue;
            
            stk.push(vN);
            while(!stk.empty()){
                if(visited[stk.top()]){ return true; }
                int nValue = stk.top(); stk.pop();
                
                visited[nValue] = 1;
                for(int &i: A[nValue]) if(!visited[i]) stk.push(i);
            }
        }
        
        return false;
    }
};

class BFS {
public:
    bool isCycle(int V, vector<int> A[]) {
        // Perform DFS To Find Cycle:
        if(V == 0) return false;

        queue<int> q;
        bitset<2001> visited;

        q.push(0);
        while(!q.empty()){
            if(visited[q.front()]){ return true; }
            int nValue = q.front(); q.pop();

            visited[nValue] = 1;
            for(int &i: A[nValue]){
                if(!visited[i]) q.push(i);
            }
        }

        return false;
    }
};

// Alternate:
// Calculate number of edges: If edges >= vertex, cycle exists. E = V - 1.
// int edges = 0;
// for(auto i: A) edges += i.size();
// cout << "\nEdges: " << (edges/2) << endl;
// edges /= 2;
// return (edges >= A.size() - 1);

int main(){
    
    return 0;
}