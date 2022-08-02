#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    //Generate Elements From Factors:
    // * Given prime factors find first n numbers containing given prime factors only.
    // * Prime Factors = 2,3,5
    // * Multiplying the generated numbers by given prime factors will be containing primefactors only.
    // * Do not use the concept of mutiples as it'll contain other prime factors.
    // * Below is the dry run for the case i = 1.
    
    int nthUglyNumber(int n) {
        vector<int> array(n, 0); 
        array[0] = 1;   //First Ugly Number

        //Pointer to the next allowed multiples of 2, 3, 5
        int indexA = 0, indexB = 0, indexC = 0; //Pointer to next allowed multiplier to generate next minimum element containing only factors of A B C, where A = 2, B = 3, C = 5
        //All the pointers points to index 0 of array i.e. value 1.
        
        int nextA, nextB, nextC;
        int mini;
        for(int i=1; i<n; i++){
            nextA = array[indexA]*2;    //Value of next multiple of A (2) --> 1x2
            nextB = array[indexB]*3;    //Value of next multiple of B (3) --> 1x3
            nextC = array[indexC]*5;    //Value of next multiple of C (5) --> 1x5
            mini = min(nextA, min(nextB, nextC));   //Find the minimum to be the next.

            if(nextA==mini) indexA++;   //Go to next multiple.  nextA = 1
            if(nextB==mini) indexB++;   //Go to next multiple.  nextB = 0
            if(nextC==mini) indexC++;   //Go to next multiple.  nextC = 0

            array[i] = mini;
        }

        return array[n-1];
    }
};

int main(){
    Solution newSol;
    cout << newSol.nthUglyNumber(10);

    return 0;
}