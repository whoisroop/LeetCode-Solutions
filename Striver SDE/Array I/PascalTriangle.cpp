// LeetCode - 118. Pascal Triangle.
#include<iostream>
#include<vector>
using namespace std;

//          1
//      \ /  \ /
//       1    1
//    \ /  \ / \ /
//     1    2   1

class Solution {
public:
    vector<vector<int>> generatePT(int totalR) {
        vector<vector<int>> pascal(totalR);
        
        pascal[0].push_back(1);
        for(int row=1; row<totalR; row++){
            for(int i=0; i<=row; i++){
                if((i-1)>=0 && (i<=(row-1))) pascal[row].push_back(pascal[row-1][i-1] + pascal[row-1][i]);
                else pascal[row].push_back(1);
            }
        }
        
        return pascal;
    }
};

int main(){
    int totalR = 5;
    Solution pascal;
    
    vector<vector<int>> ptriangle = pascal.generatePT(totalR);

    for(vector<int> &row: ptriangle){
        for(int &i: row) cout << i << " ";
        cout << endl;
    }

    return 0;
}