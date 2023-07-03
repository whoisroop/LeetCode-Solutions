// LeetCode - 
// Description - 

#include<bits/stdc++.h>
using namespace std;

class Solution{
private:

public:

};

int main(){
    Solution solve;
    vector<int> A = {1, 0, 1, 1};   // 11
    int value = 0;
    for(int i=0; i<A.size(); i++){ value = value << 1; value |= A[i]; }
    cout << value << endl;
    return 0;
}