// LeetCode - 
// Description - 

#include<bits/stdc++.h>
using namespace std;

class Solution{
private:

public:
    int solve(int N, char * A){
        int counter = 0;

        for(int i=0; i<N; i++){
            if(A[i] == '(') continue;

            while(i < N && A[i] == ')'){ i += 1; }
            counter += 1; i-=1;
        }
        
        cout << counter << endl;
        return counter;
    }

};

int main(){
    Solution solve;
    
    char * S = "(()(()))";
    int n = 8;
    solve.solve(n, S);

    return 0;
}