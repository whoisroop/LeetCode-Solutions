// UNION FIND : DISJOINT SET
// Description - 

// We need to cluster the elements.
// To cluster two clusters we need to connect a smaller to larger cluster so as to reduce the time complexity of find the ultimate parent so we save the size of clusters.
// When we cluster the elements, we assign a topmost parent or ultimate parent or can be considered as a key which can be used to check whether the elements belong to the same cluster. The newly added elements are added or connected to the ultimate parent when added to cluster.

// Union find is a way of finding connected components, for example:
// (1,2) (3,4) (5,6) & when we add an edge (5,4) The components: 3 4 5 6 are connected.
// To find whether two components are connected or not: We define a class with two data elements, parent of each element & the size of group.
// The process can be defined as:
// When we connect two elements, find the ultimate parent of both the elements, and check the size.
// The smaller size group is connected to larger group.
// The parent of all the elements in the newly formed group will the element at the topmost level, determined by a function findparent().
// The method is called path compression.
// 1 - 2    size[1] = 2     parent[2] = 1
// 3 - 4    size[3] = 2     parent[4] = 3
// 5 - 6    size[5] = 2     parent[6] = 5

// INDEX:   1 2 3 4 5 6
// SIZE:    2 1 2 1 2 1
// Parent:  1 1 3 3 5 5

// NOW CONNECT (5, 4):
// Ultimate parent of 5: 5  ; As parent[5] = 5
// Ultimate parent of 4: 3  ; As parent[4] = 3 & parent[3] = 3 (The top level element)
// SIZE[3] = 2 & SIZE[5] = 2
// Connect cluster with ultimate parent 5 to the cluster with ultimate parent 3.
// SIZE[3] += SIZE[5]
// PARENT[5] = 3

#include<bits/stdc++.h>
using namespace std;

class UnionFind{
private:
    vector<int> parent, size;
public:
    UnionFind(int N){
        parent.resize(N+1);
        size.resize(N+1);

        for(int i=0; i<=N; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    // Ultimate Parent:
    int findparent(int nValue){ 
        if(parent[nValue] == nValue) return nValue;

        return parent[nValue] = findparent(parent[nValue]); //Path Compression
    }

    // Union By Size
    void connect(int u, int v){
        int uparentU = findparent(u);
        int uparentV = findparent(v);

        if(uparentU == uparentV) return;

        if(size[uparentU] <= size[uparentV]){
            parent[uparentU] = uparentV;
            size[uparentV] += size[uparentU];
        }
        else{
            parent[uparentV] = uparentU;
            size[uparentU] += size[uparentV];
        }

        return;
    }

};

int main(){
    UnionFind dset(10);
    dset.connect(1,2);
    dset.connect(3,4);
    dset.connect(5,6);
    dset.connect(5,4);

    if(dset.findparent(3) == dset.findparent(5)) cout << "CONNECTED" << endl;
    else cout << "NOT CONNECTED" << endl;
    
    dset.connect(1,2);
    
    return 0;
}