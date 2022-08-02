#include<iostream>
#include<vector>
using namespace std;

// An ugly number is a positive integer that is divisible by a, b, or c.
// Given four integers n, a, b, and c, return the nth ugly number.
// Similar to ugly number II but we have to use multiples of each number.

class Solution{
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        int nextMultiplierA = 1;
        int nextMultiplierB = 1;
        int nextMultiplierC = 1;

        int nthUgly=0;
        int nextA, nextB, nextC;
        for(int i=0; i<n; i++){
            nextA = INT32_MAX, nextB = INT32_MAX, nextC = INT32_MAX;

            if(nextMultiplierA<(INT32_MAX/a)) nextA = a*nextMultiplierA;    //Next multiple of a
            if(nextMultiplierB<(INT32_MAX/b)) nextB = b*nextMultiplierB;    //Next multiple of b
            if(nextMultiplierC<(INT32_MAX/c)) nextC = c*nextMultiplierC;    //Next multiple of c
            int mini = min(nextA, min(nextB, nextC));

            if(mini == nextA)   nextMultiplierA++;
            if(mini == nextB)   nextMultiplierB++;
            if(mini == nextC)   nextMultiplierC++;

            nthUgly = mini;
            cout << mini << " ";
        }

        cout << endl;
        return nthUgly;
    }

};

int main(){
    Solution newSol;
    cout << newSol.nthUglyNumber(4,2,3,5);
    return 0;
}