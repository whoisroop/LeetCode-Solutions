
#include <bits/stdc++.h> 
using namespace std;

class Solution{
public:
    int subarraysXor(vector<int> &A, int x){
        int n = A.size();
        vector<int> prefix(n+1, 0);
        prefix[0] = 0;
        for(int i=0; i<n; i++) prefix[i+1] = (prefix[i]^A[i]);
        for(int i: prefix) cout << i << " ";
        cout << endl;
        
        int counter = 0;
        for(int ia=0; ia<=n; ia++){
            for(int ib=(ia+1); ib<=n; ib++){
                if((prefix[ia]^prefix[ib]) == x){
                    cout << "IA: " << ia << " IB: " << ib << " | XOR: " << (prefix[ia]^prefix[ib]) << endl; 
                    counter++;
                }
            }
        }
        
        return counter;
    }
};

int main(){
    vector<int> A = {5, 2, 9};
    Solution find;
    cout << find.subarraysXor(A, 7);
    return 0;
}