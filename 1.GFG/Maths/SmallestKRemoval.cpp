// Problem - Build the smallest OR Remove K Digits
// Link - https://practice.geeksforgeeks.org/problems/build-the-smallest2841/0
// Description - Given a non-negative integer S represented as a string, remove K digits from the number so that the new number is the smallest possible.

// Approach:
// To build the smallest number, we sort the numbers : The values go in the fashion - 
//             |
//         |   |
//     |   |   |
// |   |   |   |
// Smallest number, so as to follow the property, when the numbers are in increasing it makes smallest number & when in decreasing it's reponsible for making it greater.
// When previous > current, pop previous. Keep a counter.
// Add the current so it's added to an increasing sequence.


#include<bits/stdc++.h>
using namespace std;

class Solution{
private:
public:
    string buildLowestNumber(string A, int K){
        int N = A.size();
        string solution = "";
        for(int i=0; i<N; i++){
            while(solution.size() != 0 && solution.back() > A[i] && K > 0){ solution.pop_back(); K -= 1; }
            if(!(solution.size() == 0 && A[i] == '0')) solution += A[i];
        }
        
        while(solution.size() != 0 && K > 0){ solution.pop_back(); K -= 1; }
        return (solution.size() == 0) ? ("0") : (solution);
    }

};

int main(){
    Solution solve;
    
    return 0;
}