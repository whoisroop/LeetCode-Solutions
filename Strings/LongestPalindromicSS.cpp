// LeetCode - 
// Description - 

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool ispdrome(string &A, int i, int j){
        while(i < j) if(A[i++] != A[j--]) return false;
        return true;
    }

public:
    string longestPalin(string A){
        int N = A.size();
        
        vector<int> index(2, 0);
        int maxsize = 0;
        for(int i=0; i<N; i++){
            for(int j=i; j<N; j++){
                if((j-i+1) > maxsize && ispdrome(A, i, j)){
                    maxsize = (j-i+1);
                    index[0] = i; index[1] = j;
                }
            }
        }
        
        return A.substr(index[0], (index[1]-index[0] + 1));
    }

    
    // Precalculate pdrome[start][end] if the substring is a palindrome:
    string palindromeSS(string A){
        int n = A.size();
        if(n == 1) return A;
        if(n == 2) return (A[0] == A[1]) ? A : A.substr(0, 1);

        vector<vector<int>> pdrome(n, vector<int>(n, 0));   // pdrome[start][end] = 1 : If palindrome.

        for(int i=0; i<n; i++){
            pdrome[i][i] = 1;   //Odd Length Palindrome
            if(i < (n-1) && A[i] == A[i+1]) pdrome[i][i+1] = 1;     //Even Length Palindrome
        }

        // a[bb]a : To check abba is palindrome:
        // Check if starting & ending character are the same: a == a && The remaining sub-string [b b] is a palindrome.
        for(int size = 2; size < n; size++){
            for(int i=0; i<n; i++){
                if(i + size >= n) break;
                
                if(A[i] == A[i+size]) pdrome[i][i+size] = pdrome[i+1][i+size - 1];
            }
        }

        // SAME CODE:
        vector<int> index(2, 0);
        int maxsize = 0;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if((j-i+1) > maxsize && pdrome[i][j]){
                    maxsize = (j-i+1);
                    index[0] = i; index[1] = j;
                }
            }
        }

            return A.substr(index[0], (index[1]-index[0] + 1));
    }
};

int main(){
    Solution solve;
    
    return 0;
}