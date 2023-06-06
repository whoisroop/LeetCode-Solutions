// GFG: Number Of Islands 
// Description: https://practice.geeksforgeeks.org/problems/number-of-islands/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-islands
// Approach: 
// Each cell (i,j) is represented as a node with value: (i * M + j) ; where the matrix of size N x M.
// Now, to find the number of islands, counting ultimate parent will not work as all the cells are ultimate parent initially.
// For each cell, check if a neighboring cell is an island. If an island is found connect the two nodes.
// To track the number of islands, keep a counter.
// Increase the counter for each island node added, when the island connects to other island, make sure the connection we're making isn't already connected. If not, make the connection and decrement the counter as the group of islands will be considered as one.

// Make use of the island counter to keep track of islands and decrement when two disjoint island connects.

#include<bits/stdc++.h>
using namespace std;

class UnionFind{
private:
    vector<int> parent, size;
public:
    
    UnionFind(int N){
        parent.resize(N);
        size.resize(N);
        
        for(int i=0; i<N; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    
    int findparent(int nValue){
        if(parent[nValue] == nValue) return nValue;
        
        return parent[nValue] = findparent(parent[nValue]);
    }
    
    void connect(int u, int v){
        int upU = findparent(u);
        int upV = findparent(v);
        
        if(upU == upV) return;
        
        if(size[upU] >= size[upV]){
            parent[upV] = upU;
            size[upU] += size[upV];
        }
        else{
            parent[upU] = upV;
            size[upV] += size[upU];
        }
        
        return;
    }
};

class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // Cell Numbering: (i, j) : M * i + j = value
        // i = value / M & j = value % M
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        
        int V = n*m;
        UnionFind dset(V);
        
        vector<int> solution;
        int island = 0;
        for(auto &q: operators){
            int i = q[0], j = q[1];
            if(matrix[i][j] == 1){ solution.push_back(island); continue; }
            
            matrix[i][j] = 1;
            island += 1;
            
            int nValue = m*i + j;
            if(i-1 >= 0 && matrix[i-1][j] == 1 && dset.findparent(nValue) != dset.findparent(m*(i-1) + j)){ dset.connect(nValue, m*(i-1) + j); island -= 1; }
            if(j-1 >= 0 && matrix[i][j-1] == 1 && dset.findparent(nValue) != dset.findparent(m*(i) + j-1)){ dset.connect(nValue, m*(i) + j-1); island -= 1; }
            if(i+1 < n && matrix[i+1][j] == 1 && dset.findparent(nValue) != dset.findparent(m*(i+1) + j)){ dset.connect(nValue, m*(i+1) + j); island -= 1; }
            if(j+1 < m && matrix[i][j+1] == 1 && dset.findparent(nValue) != dset.findparent(m*(i) + j+1)){ dset.connect(nValue, m*(i) + j+1); island -= 1; }
            
            solution.push_back(island);
        }
        
        return solution;
    }
};

int main(){
    Solution solve;
    
    return 0;
}