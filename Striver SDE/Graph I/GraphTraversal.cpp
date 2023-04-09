// LeetCode -
// Description - 

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> makeGraph();

class depthFirst{
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
        return;
    }
};

class breadthFirst{
private:

public:
    // Visiting the nodes in a distance wise manner.
    void breadthFT(){
        vector<vector<int>> A = makeGraph();
        int V = A.size();

        queue<int> q;
        bitset<100001> visited;
        vector<int> traversal;
        
        q.push(0);  // 0 - Start Node
        while(!q.empty()){
            int nValue = q.front(); q.pop();
            if(visited[nValue]) continue;
            
            visited[nValue] = 1;
            traversal.push_back(nValue);

            for(int &neighbor: A[nValue]) q.push(neighbor);
        }

        cout << "\nBFS: ";
        for(int &i: traversal) cout << i << " ";
    }
};

int main(){
    depthFirst solveA;
    solveA.depthFT();

    breadthFirst solveB;
    solveB.breadthFT();

    return 0;
}

vector<vector<int>> makeGraph(){
    vector<vector<int>> N(8);

    N[0].push_back(1);
    N[0].push_back(7);
    N[1].push_back(0);
    N[1].push_back(2);
    N[1].push_back(3);
    N[2].push_back(1);
    N[3].push_back(1);
    N[3].push_back(4);
    N[4].push_back(3);
    N[4].push_back(5);
    N[4].push_back(6);
    N[5].push_back(4);
    N[6].push_back(4);
    N[6].push_back(7);
    N[7].push_back(0);
    N[7].push_back(6);
    
    return N; 
}