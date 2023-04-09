// LeetCode -
// Description - 

// To implement using iterative technique: Use two stacks, one for visiting nodes, and other to store poped out node to store the current path.
// In case the node at top of path are completely visited, pop them out.
// To detect the cycle in a directed graph, maintain a path i.e. the current path to the node and if any node is revisited along the path then there exist a cycle.
// Why visited isn't enough?
// A->B, A->C, B->D, C->D
// The visited will tell there exist a cycle when in reality there isn't.
//    B
//  /   \ 
// A      D
//  \   /
//    C

#include<bits/stdc++.h>
using namespace std;

class SolutionDFS{
private:
    bool DFS(int nValue, bitset<100001> &visited, bitset<100001> &path, vector<int> A[]){
        visited[nValue] = 1;
        path[nValue] = 1;
        
        bool cycle = false;
        for(int &neighbor: A[nValue]){
            if(path[neighbor] == 1) return true;
            if(!visited[neighbor]) cycle = DFS(neighbor, visited, path, A);
            if(cycle == true) return true;
        }

        path[nValue] = 0;
        return false;
    }

public:
    bool isCyclic(int V, vector<int> A[]) {
        // Perform DFS To Find Cycle:
        bitset<100001> visited;
        bitset<100001> path;
        bool check = false;
        
        for(int i=0; i<V; i++){
            if(visited[i]) continue;
            check = DFS(i, visited, path, A);
            
            if(check == true) return true;
        }
        
        return false;
    }
};

class SolutionTopologicalBFS{
public:
    bool isCyclic(int V, vector<int> A[]){
        vector<int> indegree(V, 0);
        for(int i=0; i<V; i++){
            for(int &neighbor: A[i]) indegree[neighbor] += 1;  //Edge to the neighbor.
        }

        queue<int> q;
        for(int i=0; i<V; i++) if(indegree[i] == 0) q.push(i);
        // vector<int> order;
        int counter = 0;

        // Visited is not required, as the traversal is on the basis on indegree value.
        while(!q.empty()){
            int nValue = q.front(); q.pop();
            // order.push_back(nValue);
            counter += 1;

            for(int &neighbor: A[nValue]){
                indegree[neighbor] -= 1;
                if(indegree[neighbor] == 0) q.push(neighbor);
            }
        }

        // reverse(order.begin(), order.end());
        return (counter == V);
    }
};

int main(){

    return 0;
}