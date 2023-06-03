// GFG: Count the number of possible triangles.
// Description: Given an unsorted array A[] of n positive integers. Find the number of triangles that can be formed with three different array elements as lengths of three sides of triangles. 
// Approach: 

// A + B > C
// A + B - C > 0
// Also, A+B>C AND A+C>B AND B+C>A
// Check: A + B > C : Choose C to be the max side length, C > A & C > B
// Now, if the condition A + B > C satisfies, (C + A > C) --> (C + A > B) & (C + B > C) --> (C + B > A), satisfied as C > A & C > B

// Example: 3 4 5
// 3 + 4 > 5 All the other conditions are also satisfied.

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to count the number of possible triangles.
    int findNumberOfTriangles(int A[], int N){
        sort(A, A+N);

        int counter = 0;
        for(int p=N-1; p>1; p--){
            int C = A[p];
            
            int i=0, j=p-1;
            while(i<j){
                int sum = A[i] + A[j] - C;
                if(sum > 0){ counter += (j-i); j -= 1; } 
                else i += 1;
            }
        }
        
        return counter;
    }
};

int main(){
    Solution solve;
    
    return 0;
}