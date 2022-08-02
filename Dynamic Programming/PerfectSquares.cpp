// Given an integer n, return the least number of perfect square numbers that sum to n.
// A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.
//Example: 23 = 9 + 9 + 4 + 1 RETURN 4
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

class Solution {
private:
    int findMinElements(vector<int> &array, int target){
        int n = array.size();
        int li = n-1;
        vector<vector<int>> dp(n, vector<int>(target+1, 1e8));

        //if(i==0){
            //if(target==0) return 0;
            //else if(target%array[0]==0)  return    (target/array[0]);
            //else return 1e8;
        //}

        //Base Case
        dp[0][0] = 0;
        for(int t=0; t<=target; t++){
            if((t%array[0]) == 0)   dp[0][t] = (t/array[0]);
        }

        for(int i=1; i<n; i++){
            for(int t=0; t<=(target); t++){
                int take = 1e8;
                if(array[i]<=t) take = 1 + dp[i][t-array[i]];
                int notTake = 0 + dp[i-1][t];

                dp[i][t] = min(take, notTake);
            }
        }

        return dp[li][target];
    }

public:
    int perfectSquares(int value){
        int n = sqrt(value);
        vector<int> squares(n, 0);

        for(int i=0; i<n; i++){
            squares[i] = (i+1)*(i+1);
        }

        //Squares Vector
        for(int i: squares) cout << i << " ";
        cout << endl;

        //Let n = 23 --> sqrt(23) = 4 | squares = {1, 4, 9, 16} 
        int minElements = findMinElements(squares, value);

        return minElements;
    }

};

int main(){
    int x = 23;
    Solution newSol;
    cout << newSol.perfectSquares(x);
}