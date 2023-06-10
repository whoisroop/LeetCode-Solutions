// GFG: Knight Walk.
// Description: Given a square chessboard, the initial position of Knight and position of a target. Find out the minimum steps a Knight will take to reach the target position.If it cannot reach the target position return -1.
// Approach: 
// BFS & storing number of moves.
// Take all the possible move from the current position.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxmax = 1e8;
    
    bool valid(int i, int j, int nr, int nc){
        return (i>=0 && j>=0 && i<nr && j<nc);
    }
    
	int minStepToReachTarget(vector<int>&K, vector<int>&T, int N){
	    int ki = K[0]-1, kj = K[1]-1;
	    int ti = T[0]-1, tj = T[1]-1;
	    
	    vector<vector<int>> visited(N, vector<int>(N, 0));
	    int nr = N, nc = N;
	    
	    queue<pair<int, pair<int, int>>> q;
	    q.push({0, {ki, kj}}); visited[ki][kj] = 1;
	    
	    while(q.empty() != true){
	        auto top = q.front(); q.pop();
	        int moves = top.first;
	        int i = top.second.first, j = top.second.second;
	        
	        if(i == ti && j == tj) return moves;
	        
	        vector<int> di = {2, 2, -2, -2, 1, -1, 1, -1};
	        vector<int> dj = {1, -1, 1, -1, 2, 2, -2, -2};
	        for(int x=0; x<8; x++){
	            int ii = i + di[x];
	            int jj = j + dj[x];
	            
	            if(valid(ii, jj, nr, nc) && visited[ii][jj] == 0){
	                visited[ii][jj] = 1;
	                q.push({moves+1, {ii, jj}});
	            }
	        }
	    }
	    
	    return -1;
	}
};

int main(){
    Solution solve;
    
    return 0;
}