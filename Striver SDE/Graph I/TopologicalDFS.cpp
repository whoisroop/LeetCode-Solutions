// GFG: Topological Sorting. DFS.
// Description - 
// Approach:
// Approch the solution in reverse. The nodes with no outgoing edges are to be processed at last, are the ones at the end of the chain.
// Start a DFS algorithm and whenever we hit the last node, add it to the ordering.
//              1
//             /
// 4 -> 3 -> 0 
//             \ 
//              2
// DFS(0) --> DFS(1) & DFS(2) : Order (1, 2, 0)
// DFS(3) --> Order(1, 2, 0, 3)
// DFS(4) --> Order(1, 2, 0, 3, 4)
// Reverse - 4 3 0 1 2 Topological Order.

#include<bits/stdc++.h>
using namespace std;

class Solution{
private:
    void DFS(int nValue, bitset<100001> &visited, vector<int> A[], vector<int> &order){
        visited[nValue] = 1;
        for(int &neighbor: A[nValue]) if(!visited[neighbor]) DFS(neighbor, visited, A, order);

        order.push_back(nValue);    //The end of path. No more nodes to process.
        return;
    }

public:
    vector<int> topoSort(int V, vector<int> A[]) {
	    bitset<100001> visited;
        vector<int> order;

        for(int i=0; i<V; i++){
            if(visited[i]) continue;
            DFS(i, visited, A, order);
        }

        reverse(order.begin(), order.end());
        return order;
	}

};

int main(){
    Solution solve;
    
    return 0;
}