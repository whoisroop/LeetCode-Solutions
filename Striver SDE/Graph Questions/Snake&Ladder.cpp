// Problem - Snake and Ladder Problem.
// Link - https://practice.geeksforgeeks.org/problems/snake-and-ladder-problem4816/1?page=1&status[]=attempted&sortBy=submissions 
// Description - 

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int minThrow(int K, int snakes[]){
        unordered_map<int, int> move;   //From Square To Square
        for(int i=1; i<=30; i++) move[i] = i;
        for(int i=0; i<2*K; i += 2) move[snakes[i]] = snakes[i+1];
        
        // BFS SOLUTION: 
        
        queue<pair<int, int>> q;    //Position, Moves : Dijkstra's
        q.push({1, 0});
        
        bitset<31> visited;
        while(q.empty() != true){
            auto top = q.front(); q.pop();
            int position = top.first; int steps = top.second;
            if(position == 30) return steps;
            for(int i=1; i<=6; i++) if(!visited[position + i] && position + i <= 30) q.push({move[position + i], steps + 1});
        }
        
        
        return -1;
    }
};

int main(){
    Solution solve;
    
    return 0;
}