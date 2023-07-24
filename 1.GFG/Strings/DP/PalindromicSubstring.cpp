// Problem - Longest Palindromic Substring.
// Description - 
// TC O(N^2) Otherwise O(N^3) using standard method of looping.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Precalculate pdrome[start][end] if the substring is a palindrome:
    string palindromeSS(string A){
        int n = A.size();
        if(n == 1) return A;
        if(n == 2) return (A[0] == A[1]) ? A : A.substr(0, 1);

        vector<vector<int>> pdrome(n, vector<int>(n, 0));   // pdrome[start][end] will store size, if A[start...end] is a palindrome.

        for(int i=0; i<n; i++){
            pdrome[i][i] = 1;   //Odd Length Palindrome : Every single character is a palindrome.
            if(i < (n-1) && A[i] == A[i+1]) pdrome[i][i+1] = 1;     //Even Length Palindrome : If two consecutive characters match.
        }

        // Now break the problem into subproblem or substring, (a)xbx(a) if the characters at the edge of the window match, check if (i+1, j-1) is a palindrome i.e. if pdrome[i+1][j-1] != 0; If it is palindrome, set the value pdrome[i][j] = pdrome[i+1][j+1] + 1 + 1;  // + 1 For Edge Element.
        // a xbx a = xbx + 1(a) + 1(a)

        // a[bb]a : To check abba is palindrome:
        // Check if starting & ending character are the same: a == a && The remaining sub-string [b b] is a palindrome.
        for(int size = 2; size < n; size++){
            for(int i=0; i<n; i++){
                if(i + size >= n) break;

                //If the characters on the edge match & the inside is palindrome (size != 0) set the value = size of inner palindrome + 2 (edge elements).
                if(A[i] == A[i+size] && pdrome[i+1][i+size - 1] != 0) pdrome[i][i+size] = pdrome[i+1][i+size - 1] + 2;  
            }
        }

        // SAME CODE: To print palindrome:
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