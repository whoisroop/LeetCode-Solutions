// GFG - Find the number of elements which is divisible by atleast on other element in the array.
// Description - 

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countSpecialNumbers(int N, vector<int> A) {
        sort(A.begin(), A.end());
        
        int maxV = A[A.size() - 1];
        
        bitset<100001> divisor;
        int counter = 0;
        
        for(int i=0; i < N; i++){
            if(divisor[A[i]]){ counter += 1; continue; }
            
            if(i < N && A[i] == A[i+1]){
                while(i < N && A[i] == A[i+1]){ 
                    counter += 1; 
                    i += 1; 
                } 
                counter += 1;
            }
            
            int value = A[i];
            for(int j = 2*value; j <= maxV; j += value) divisor[j] = 1;
        }
        
        return counter;
    }
};

int main(){
    Solution solve;
    
    return 0;
}