#include<bits/stdc++.h>
using namespace std;

#include "makegraph.h"

class Solution{
private:
    void DFS(int value, vector<int> &traversal, bitset<100001> &visited, vector<vector<int>> &A){
        visited[value] = 1;
        traversal.push_back(value);

        for(int &i: A[value]){
            if(!visited[i]) DFS(i, traversal, visited, A);
        }

        return;
    }

public:
    void depthFT(){
        vector<vector<int>> A = makeGraph();
        int V = A.size();

        vector<int> traversal;
        bitset<100001> visited;

        DFS(0, traversal, visited, A);  //0 - Start Node

        cout << "\nDFS: ";
        for(int &i: traversal) cout << i << " ";

        int edges = 0;
        for(auto i: A) edges += i.size();
        cout << "\nEdges: " << (edges/2) << endl;
        return;
    }
};

int main(){
    Solution solve;
    solve.depthFT();
    return 0;
}