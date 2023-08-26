// LeetCode: 
// Description: 
// Approach: 

#include<bits/stdc++.h>
using namespace std;

class Solution{
private:
public:
    void DFS(int nValue, vector<int> &visited, vector<int> &color, vector<vector<int>> &A, int &maxcolor){
        visited[nValue] = 1;
        
        set<int> avoid;
        for(int &neighbor: A[nValue]) if(color[neighbor] != 0) avoid.insert(color[neighbor]);
        
        // Assign Color:
        int assign = 1;
        while(avoid.count(assign)) assign += 1;
        color[nValue] = assign;
        maxcolor = max(maxcolor, assign);

        for(int &neighbor: A[nValue]) if(color[neighbor] == 0) DFS(neighbor, visited, color, A, maxcolor);

        return;
    }
};

int main(){
    Solution solve;
    int N = 2;
    vector<vector<int>> E;
    // E.push_back({1,2});
    // E.push_back({1,4});
    // E.push_back({2,7});
    // E.push_back({3,4});
    // E.push_back({4,5});
    // E.push_back({4,6});
    // E.push_back({5,6});
    // E.push_back({7,1});
    E.push_back({1,2});

    vector<vector<int>> A(N);
    for(auto edge: E){ //E - Edge list
        A[edge[0] - 1].push_back(edge[1]-1);
        A[edge[1] - 1].push_back(edge[0]-1);
    }

    vector<int> visited(N, 0);
    vector<int> color(N, 0);
    int maxcolor = 1;

    solve.DFS(0, visited, color, A, maxcolor);
    cout << maxcolor << endl; 

    return 0;
}