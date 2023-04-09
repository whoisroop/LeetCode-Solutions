// GFG: Topological Sorting - KAHN's ALGORITHM.
// Description - 
// https://www.youtube.com/watch?v=73sneFXuTEg&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=23&ab_channel=takeUforward

// TOPOLOGICAL SORTING CAN ONLY BE DONE ON DAG.

// Approach:
// Simple, at first calculate the indegree of all the nodes.
// The indegree denotes the number of task to be done or the number of node to be processed before the current node.
// The node with indegree 0 is the first node as it doesn't require any node to be processed before the current one.
// When a node is processed, check its neighbors and reduce their indegree by 1, as the current node is processed so there'll be one less in the order.
// When a node with indegree 0 is found while processing the neighbors, insert it into the queue.
// Repeat the process.

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
	vector<int> topoSort(int V, vector<int> A[]) {
	    vector<int> indegree(V, 0);
	    for(int i=0; i<V; i++){
	        for(int &j: A[i]) indegree[j] += 1;
	    }
	    
	    queue<int> q;
	    for(int i=0; i<V; i++) if(indegree[i] == 0) q.push(i);
	    
	    vector<int> sorted;
	    
	    while(!q.empty()){
	        int nValue = q.front(); q.pop();
	        for(int &neighbor: A[nValue]){ 
	            indegree[neighbor] -= 1; 
	            if(indegree[neighbor] == 0) q.push(neighbor); 
	        }
	        
	        sorted.push_back(nValue);
	    }
	    
	    return sorted;
	}
};

int main(){
    Solution solve;
    
    return 0;
}