// LeetCode - 133. Clone Graph.
// Description - Given a reference of a node in a connected undirected graph.
// Return a deep copy (clone) of the graph.
// Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

#include<bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* start) {
        if(start == NULL) return NULL;

        unordered_map<Node *, Node *> visited;  //Graph Node --> Clone Node

        queue<Node *> q;
        q.push(start);
        while(!q.empty()){
            int n = q.size();
            for(int i=0; i<n; i++){
                Node * node = q.front(); q.pop();
                Node * nnode = new Node(node->val);
                for(auto &i: node->neighbors){ 
                    if(visited.find(i) == visited.end()){
                        q.push(i);
                    }
                    nnode->neighbors.push_back(i);  //Original nodes are pushed into the neighbors array of every clonned node.
                }

                visited[node] = nnode;
            }
        }

        for(auto &mapping: visited){
            for(auto &j: mapping.second->neighbors) j = visited[j]; //The original nodes are replaced with clonned nodes.
        }

        return visited[start];
    }
};

int main(){
    Solution solve;
    
    return 0;
}