// LeetCode - 
// Description - 

#include<bits/stdc++.h>
using namespace std;

class Solution{
private:

public:
    int maximize(int N, int K, int * A){
        sort(A, A+N);
        int index = (N%2 == 0) ? N/2 - 1 : N/2;
        int median = A[index];
        int counter = 0;

        for(int i=0; i<N; i++) if(abs(A[i] - median) <= K) counter += 1;
        
        cout << counter << endl;
        return counter;
    }
};

int main(){
    Solution solve;
    int A[] = {2,2,5,6};
    solve.maximize(4, 0, A);
    return 0;
}