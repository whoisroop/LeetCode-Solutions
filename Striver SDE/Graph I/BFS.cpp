// GFG - BFS OF A GRAPH.
// Description - 

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> vertex[]) {
        if(V == 0) return {};
        
        queue<int> q;
        bitset<10001> visited;
        vector<int> BFS;
        
        q.push(0);
        while(!q.empty()){
            if(visited[q.front()]){ q.pop(); continue; }
            int nValue = q.front(); q.pop();
            
            BFS.push_back(nValue); 
            visited[nValue] = 1;
            
            vector<int> neighbors = vertex[nValue];
            for(int j=0; j<neighbors.size(); j++) 
                if(!visited[neighbors[j]]) q.push(neighbors[j]);
        }

        return BFS;
    }
};

int main(){
    Solution solve;
    
    return 0;
}