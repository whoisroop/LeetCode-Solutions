#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> pascalRow(int row) {
       vector<int> elements(row+1, 1);
       int x = 1;
       for(int i=1; i<(row); i++){
            x = ((1LL)*x*(row - (i) + 1))/(i);    //ShortCut To Calculate nCr = (n-r+1)/r x nCr-1
            elements[i] = x;
       }

       return elements;
    }
};

int main(){
    Solution newSol;
    int n = 4;
    vector<int> x = newSol.pascalRow(n);
    for(int i: x)   cout << i << " ";
}