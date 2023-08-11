// Given a string, find the length of the longest substring without repeating characters.
// Example:
// Input: "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.
 
#include<bits/stdc++.h>
using namespace std;

class Solution{
private:
public:
    int longest(string A){
        int N = A.size();
        int i=0, j=0;
        vector<int> F(26, 0);
        int maxsize = 0;
        while(j < N){
            F[A[j] - 'a'] += 1;

            while(F[A[j] - 'a'] > 1){ F[A[i] - 'a'] -= 1; i += 1; } //Decrement the window size.
            maxsize = max(maxsize, (j-i+1)); 
            
            j += 1;
        }

        return maxsize;
    }
  
};

int main(){
    Solution solve;
    string A = "rooplala";
    cout << solve.longest(A);
    return 0;
}