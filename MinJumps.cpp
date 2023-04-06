// LeetCode -
// Description - 

#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int jump(int index, int * A, int N, vector<int> &DP){
        if(index >= N-1) return 0;
        
        if(DP[index] != -1) return DP[index];
        
        int minJump = 1e9;
        for(int i=1; i<=A[index]; i++){
            int path = 1 + jump(index + i, A, N, DP);
            minJump = min(minJump, path);
        }
        
        return DP[index] = minJump;
    }
    
    int minJumps(int A[], int n){
        vector<int> DP(n + 1, -1);
        int jumps = jump(0, A, n, DP);
        
        if(jumps < 1e9) return jumps;
        else return -1;
    }
};

int main(){
    Solution solve;
    int A[] = {
        
    };
    int n = 486589;
    solve.minJumps(A, n);
    return 0;
}