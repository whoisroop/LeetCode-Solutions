// GFG - DFS OF A GRAPH.
// Description - 

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> A[]) {
        if(V == 0) return {};

        stack<int> stk;
        bitset<10001> visited;
        vector<int> DFS;
        
        stk.push(0);
        while(!stk.empty()){
            if(visited[stk.top()]){ stk.pop(); continue; }
            int nValue = stk.top(); stk.pop();
            
            DFS.push_back(nValue); 
            visited[nValue] = 1;
            
            vector<int> neighbors = A[nValue];
            for(int i = neighbors.size()-1; i >= 0; i--) 
                if(!visited[neighbors[i]]) stk.push(neighbors[i]);
        }

        return DFS;
    }
};

int main(){
    Solution solve;
    
    return 0;
}