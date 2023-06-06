// LeetCode - 1319. Number of Operations to Make Network Connected.
// Description - 
// There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] represents a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.

// You are given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.

// Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.

// Approach:
// Using disjoint set, find the cluster of components, we will require N-1 edges for a total of N cluster of components or connected graphs.
// How to find extra edges? Whenever we try to connect two elements which are already connected increment a counter variable.
// How to find number of cluster?
// Check the ultimate parent: parent[i] = i ; count total such ultimate parents.


#include<bits/stdc++.h>
using namespace std;

class UnionFind{
public:
    vector<int> parent, size;
    int extra;  //Extra Edges

    UnionFind(int N){
        parent.resize(N+1);
        size.resize(N+1);
        extra = 0;

        for(int i=0; i<=N; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findparent(int nValue){
        if(parent[nValue] == nValue) return nValue;

        return parent[nValue] = findparent(parent[nValue]);
    }

    void connect(int u, int v){
        int uparentU = findparent(u);
        int uparentV = findparent(v);

        if(uparentU == uparentV){ extra += 1; return; }

        if(size[uparentU] <= size[uparentV]){
            parent[uparentU] = uparentV;
            size[uparentV] += size[uparentU];
        }
        else{
            parent[uparentV] = uparentU;
            size[uparentU] += size[uparentV];
        }
    }
};

class Solution {
public:
    int makeConnected(int N, vector<vector<int>>& connections) {
        UnionFind dset(N);
        for(auto &connection: connections) dset.connect(connection[0], connection[1]);

        int cluster = 0;
        for(int i=0; i<N; i++) if(dset.parent[i] == i) cluster += 1;
        return (dset.extra >= (cluster-1)) ? (cluster - 1) : -1;
    }
};

int main(){
    Solution solve;
    
    return 0;
}