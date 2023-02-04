// LeetCode -
// Description - 

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int minMoves(int value, vector<int> &DP){
        if(value == 1) return 0;
        if(value < 1) return INT32_MAX;

        if(value < 10000001 && DP[value] != -1) return DP[value];

        int pathA = INT32_MAX;
        if(value%3 == 0) pathA = 1 + minMoves(value/3, DP);
        
        int pathB = INT32_MAX;
        if(value%2 == 0) pathB = 1 + minMoves(value/2, DP);

        int pathC = 1 + minMoves(value - 1, DP);

        if(value < 10000001) DP[value] = min(pathA, min(pathB, pathC));
        return min(pathA, min(pathB, pathC));
    }
};

int main(){
    Solution solve;
    vector<int> DP(10000001, -1);
    DP[1] = 0; DP[2] = 1; DP[3] = 1;

    int Q = 0;
    cin >> Q;
    for(int i=0; i<Q; i++){
        int value = 0;
        cin >> value;

        cout << solve.minMoves(value, DP) << endl;
    }

    return 0;
}