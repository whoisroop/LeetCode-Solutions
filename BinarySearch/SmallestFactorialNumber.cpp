// GFG - Smallest factorial number.
// Description - Given a number n. The task is to find the smallest number whose factorial contains at least n trailing zeroes.

// Approach:
// Zeros are generated by multiplying 5 & 2.
// For a factorial of a number N: The number of zeros = Number of 5's
// Total Occurences Of 5 = (N/5) + (N/25) + (N/125) + ...
// Now create a search space of multiples of 5: 5 10 15 20 25 ...
// Apply binary search and calculate the number of zeros.

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int zeros(int value){
        int occurence = 0;
        int multiple = 5;
        
        while(value >= multiple){
            occurence += value / multiple;
            multiple *= 5;
        }
        
        return occurence;
    }
    
    int findNum(int tzeros){
        int i=1, j=10001;
        
        long long int factorial = 0;
        while(i<=j){
            int midpoint = (i + (j-i)/2);
            long long int multiple = 5 * midpoint;
            
            if(zeros(multiple) >= tzeros){ factorial = multiple; j = midpoint - 1; }
            else i = midpoint + 1;
        }
        
        return factorial;
    }
};

int main(){
    Solution solve;
    
    return 0;
}