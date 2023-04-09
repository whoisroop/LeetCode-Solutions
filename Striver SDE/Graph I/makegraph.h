#include<bits/stdc++.h>
using namespace std;

//          0
//        /   \ 
//      7       1
//      |       | \ 
//      6       3  2
//        \    / 
//          4
//          |
//          5

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