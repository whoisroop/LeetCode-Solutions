// LeetCode -
// Description - 

#include<bits/stdc++.h>
using namespace std;

// Bipartite Graph: Graph with a cycle containing odd vertices.
// Can be colored using only two colors, with different colors on adjacent vertices.

// Color: 1 & -1
class BipartiteDFS{
public:
    bool DFS(int nValue, vector<int> &visited, vector<int> &color, vector<int> A[]){
        visited[nValue] = 1;
        for(int &neighbor: A[nValue]){
            // Colored with same color (1, 1) (-1, -1)
            if(color[nValue] * color[neighbor] == 1) return false;  //Check if the neighbor is already colored, is it the same color?

            if(color[neighbor] == 0){   //If not colored color it with the opposite of the current node color.
                color[neighbor] = -1 * color[nValue];
                bool check = DFS(neighbor, visited, color, A);
                if(check == false) return false;
            }
        }

        return true;
    }
    
	bool isBipartite(int V, vector<int>A[]){
	    if(V == 0) return true;
	    vector<int> color(V, 0);
	    vector<int> visited(V, 0);
        
        bool check = true;
        for(int i=0; i<V; i++){
            if(visited[i]) continue;
            
            color[i] = 1;
            check = DFS(i, visited, color, A);
            if(check == false) return false;
        }
        
        return true;
	}

};

class BipartiteBFS{
public:
	bool isBipartite(int V, vector<int>A[]){
	    if(V == 0) return true;
	    vector<int> color(V, 0);
	    vector<int> visited(V, 0);
        
        for(int i=0; i<V; i++){
            if(visited[i]) continue;

            queue<int> q;
            q.push(i); color[i] = 1;

            while(!q.empty()){
                int nValue = q.front(); q.pop();
                if(visited[nValue]) continue;
                
                visited[nValue] = 1;

                for(int &neighbor: A[nValue]){
                    if(color[nValue] == color[neighbor]) return false;
                    if(color[neighbor] == 0){
                        color[neighbor] = -1 * color[nValue];
                        q.push(neighbor);
                    }
                }
            }
        }
        
        return true;
	}

};

int main(){
    // Solution solve;
    
    return 0;
}