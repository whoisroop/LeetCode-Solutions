// GFG - Given a string str consisting of only two characters 'a' and 'b'. You need to find the minimum steps required to make the string empty by removing consecutive a's and b's.
// Description - 

// Approach:
// Its efficient to remove on specific character. Let the starting character be 'a', as all the b's will be removed leaving a string consisting of only a's, which can be removed in one move.
// GREEDY!

#include<bits/stdc++.h>
using namespace std;

class Solution{
private:

public:
    int minSteps(string A) {
    int n = A.size();
    int counter = 0;
    char start = A[0];
    
    for(int i=0; i<n; i++){
        if(A[i] != start){
            while(i < n && A[i] != start) i += 1;
            i -= 1;
            counter += 1;
        }
    }
    counter += 1;
    return counter;
}
};

int main(){
    Solution solve;
    
    return 0;
}