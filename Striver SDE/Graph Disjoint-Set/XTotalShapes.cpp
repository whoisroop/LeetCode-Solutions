// GFG: X Total Shapes. 
// Description: Find number of components connected.
// Approach: 

#include<bits/stdc++.h>
using namespace std;

class UnionFind{
private:
public:
    vector<int> parent, size;
    
    UnionFind(int N){
        parent.resize(N+1);
        size.resize(N+1);
        
        for(int i=0; i<N; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    
    int findparent(int nV){
        if(parent[nV] == nV) return nV;
        
        return parent[nV] = findparent(parent[nV]);
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

class Solution{
public:
    //Function to find the number of 'X' total shapes.
    int xShape(vector<vector<char>>& A) {
        // nV = i * ROW LENGTH + j
        
        int CL = A.size();
        int RL = A[0].size();
        
        int V = CL*RL;
        UnionFind dset(V);
        
        for(int i=0; i<CL; i++){
            for(int j=0; j<RL; j++){
                if(A[i][j] == 'O') continue;
                
                if(i+1 < CL && A[i+1][j] == 'X') dset.connect(i*RL + j, (i+1)*RL + j);
                if(j+1 < RL && A[i][j+1] == 'X') dset.connect(i*RL + j, i*RL + j+1);
            }
        }
        
        int counter = 0;
        for(int nV=0; nV<V; nV++){
            if(dset.findparent(nV) == nV && A[nV/RL][nV%RL] == 'X') counter += 1;
        }
        
        return counter;
    }
};

int main(){
    Solution solve;
    vector<vector<char>> A = {{'X', 'X', 'O'}, {'O', 'O', 'X'}, {'X', 'O', 'X'}};
    cout << solve.xShape(A);
    
    return 0;
}