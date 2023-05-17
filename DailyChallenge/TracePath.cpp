// GFG: Trace Path.
// Description - There is a rectangular path for a Train to travel consisting of n rows and m columns. The train will start from one of the grid's cells and it will be given a command in the form of string s consisting of characters L, R, D, U. Find if it is possible to travel the train inside the grid only.

#include<bits/stdc++.h>
using namespace std;

// Calculate the max displacement from current position.
class Solution{
public:
    int isPossible(int n, int m, string s){
        int vertical = 0, horizontal = 0;
        int maxL = 0, maxR = 0, maxU = 0, maxD = 0;

        for(char &c: s){
            if(c == 'U'){
                vertical += 1;
                maxU = max(maxU, vertical);
            }
            else if(c == 'D'){
                vertical -= 1;
                maxD = min(maxD, vertical);
            }
            else if(c == 'L'){
                horizontal -= 1;
                maxL = min(maxL, horizontal);
            }
            else{
                horizontal += 1;
                maxR = max(maxR, horizontal);
            }
            
            if(maxU-maxD >= n || maxR-maxL >= m) return 0;
        }
        
        return 1;
    }
};

int main(){
    Solution solve;
    
    return 0;
}