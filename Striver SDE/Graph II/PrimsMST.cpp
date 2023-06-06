// GFG: Minimum Spanning Tree
// Description: Given a weighted, undirected and connected graph of V vertices and E edges. The task is to find the sum of weights of the edges of the Minimum Spanning Tree.
// Approach:
// The prims algorithm follows selecting the minimum weighted edge in the given scope, hence perform a BFS by taking the edge weights as a reference, the minimum one selected first.

#include<bits/stdc++.h>
using namespace std;

class Solution{
private:
public:
  int spanningTree(int V, vector<vector<int>> A[]){
        int weight = 0;
        vector<bool> visited(V, false);
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minheap;
        minheap.push({0, 0});   // Start From Node: 0
        
        while(minheap.empty() != true){
            auto top = minheap.top(); minheap.pop();
            int edgeW = top.first;
            int nValue = top.second;
            
            if(visited[nValue]) continue;
            else visited[nValue] = 1;
            
            weight += edgeW;
            
            for(auto &NN: A[nValue]){
                int neighbor = NN[0], W = NN[1];
                if(visited[neighbor]) continue;
                
                minheap.push({W, neighbor});
            }
        }
        
        return weight;
    }
};

int main(){
    Solution solve;
    
    return 0;
}