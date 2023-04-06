// LeetCode -
// Description - 

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> A[]) {
        // Perform DFS To Find Cycle:
        if(V == 0) return false;
        
        stack<int> stk;
        bitset<100001> visited;
        bitset<100001> path;
        
        for(int vN = 0; vN < V; vN++){
            if(visited[vN] == 1) continue;
            
            stk.push(vN);
            while(!stk.empty()){
                if(visited[stk.top()]){ return true; }
                int nValue = stk.top(); stk.pop();
                
                visited[nValue] = 1;
                path[nValue] = 1;
                int counter = 0;
                for(int &i: A[nValue]){ if(!visited[i]){ stk.push(i); counter += 1; } }
                if(counter == 0) path[nValue] = 0;
            }
        }
        
        return false;
    }
};

int main(){
    Solution solve;

    return 0;
}