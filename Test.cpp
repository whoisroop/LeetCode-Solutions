// LeetCode: 
// Description: 
// Approach: 

#include<bits/stdc++.h>
using namespace std;

class Solution{
private:
public:
    int findmax(string A){
        int N = A.size();
        vector<vector<int>> F(26, vector<int>(N+1, 0));
        vector<int> maxcount(26, 0);
        
        for(int i=0; i<N; i++){
            F[A[i] - 'a'][i + 1] =  F[A[i] - 'a'][i] + 1;
            
            int maxvalue = 0;
            for(int j=0; j<26; j++){
                F[j][i+1] = max(F[j][i], F[j][i+1]);
                maxvalue = max(maxvalue, F[j][i+1]);
            }

            for(int j=0; j<26; j++){
                if(F[j][i+1] == maxvalue) maxcount[j] += 1;
            }
        }

        int maxV = 0;
        for(int i=0; i<26; i++) maxV = max(maxV, maxcount[i]);

        return maxV;
    }
};

int main(){
    Solution solve;
    // string A = "adbcbcbcc";
    // cout << solve.findmax(A) << endl;

    int x = 5;
    int y = (++x) * (x--) * (x++);
    cout << y << " - " << x << endl;

    return 0;
}