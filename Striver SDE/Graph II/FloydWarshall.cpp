//GFG: FloydWarshall Algorithm
//Description: 
// Floyd-Warshall's: (Representation - Matrix)
// * Multisource shortest path algorithm, finds the distance from every single vertex to all the other vertex.
// * The concept of junction: Breaking down the path with the help of a junction.
// * Edge List: (1,2, W: 1) (2,3, W:1) (2,0, W:5) (3,0, W:2)

//           3
//         / |
// 1 -> 2    |
//         \ v
//           0

// * Lets focus on a single path for understanding: The path from 1 to 0 can be divided into multiple paths:
// * Via 0, Via 1 no update on any paths lengths or distance.
// * Initial update will be via 2: 1 to 3 will be 1->2 + 2->3 = 2, also 1 to 0 will be 1->2 + 2->0 = 6.
// * Next update: Via 3
// * 1 to 0 via 3: 1->3 + 3->0 = 2 + 2 = 4 New Minimum!    (1->3 was calculated via 2)
// * Here, the path 1 to 0 was broken down into 1 to 3 and 3 to 0.
// * 1 to 3 joining at junction 2 & 1 to 0 joining at junction 3.

// * If we switch order in which the vertex are processed:
// * Edge List: (1,2, W: 1) (3,2, W:1) (3,0, W:5) (2,0, W:2)
// * The weights are same, just the vertex are interchanged so as the processing order is changed.

//           2
//         / |
// 1 -> 3    |
//         \ v
//           0

// * Here, the via 2 will be calculated first giving us 3 to 0 via 2 as the junctions.
// * Then, the via 3 will give 1->3 + 3->0 (calculated using 2).
// * The paths can be divided into segments and can processed in anyorder, but the joining them by junctions order will yeild the same path.
// * 3 to 0 joining at junction 2 & 1 to 0 joining at junction 3.

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxmax = 1e6;
    
	void shortest_distance(vector<vector<int>> &A){
	    int V = A.size();
	    
	    for(int i=0; i<V; i++){
	        for(int j=0; j<V; j++) if(A[i][j] == -1) A[i][j] = maxmax;
	    }
	    
	    for(int junction = 0; junction < V; junction++){
	        for(int i = 0; i < V; i++){
	            for(int j = 0; j < V; j++){
	                A[i][j] = min(A[i][j], (A[i][junction]+A[junction][j]));
	            }
	        }
	    }
	    
	    for(int i=0; i<V; i++){
	        for(int j=0; j<V; j++) if(A[i][j] == maxmax) A[i][j] = -1;
	    }
	    
	    return;
	}
};

int main(){
    Solution solve;
    
    return 0;
}