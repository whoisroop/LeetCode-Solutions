#include<bits/stdc++.h>
using namespace std;

// Problem Statement - 
// Link - https://practice.geeksforgeeks.org/problems/maximum-sub-string-after-at-most-k-changes3220/1
// We have a string s of length n, which contains only UPPERCASE characters and we have a number k (always less than n). We can make at most k changes in our string. In one change, you can replace any s[i] (0<= i < n) with any uppercase character (from 'A' to 'Z'). After k changes, find the maximum possible length of the sub-string which has all the same characters.

// Example: AABABB & K = 1
// Either replace the character B at index = 2 to get string "AAAABB" : SOLUTION = 4
// Or replace the  character A at index = 3 to get string "AABBBB" : SOLUTION = 4
// Solution = 4, which is the maximum length of the substring of the same character that we can achieve by altering K = 1 character in the string.

// We alter all the characters to the most repeating or most frequent character in the window or the string.

// This itself strikes the thought of sliding window solution, but how to approach the problem?
// 1. We declare & store the frequency of the elements in the window in a vector - vector<int> F(26, 0)
// 2. We alter all the characters to the most repeating or most frequent character in the window.
// 3. For each iteration check if the number of elements to be converted: TOTAL ELEMENTS (IN WINDOW) - FREQUENCY OF MOST FREQUENT ELEMENT (IN WINDOW) < K 
//      If the condition satisfies, continue to add the element into the window.
//      Store the candidate for solution: maxsize = max(maxsize, (j-i+1)) or maxsize = max(current max size, current window length).
//      Explanation: ABA - Total Elements = 3, Max Frequency = 2 ('A')
//      For K = 2, Replace B to A & one of A's to A
// 4. When, TOTAL ELEMENTS - FREQUENCY OF MOST FREQUENT ELEMENT > K (i.e. we have one excess element apart from the most frequent element)
//      Remove one element from the left end of the window, and decrement the window size (to maintain the current window size, in the next iteration we increase it j++ ). 
//      We maintain the size of the window only to increase it, as the better solution would have the window size greater than the current maxsize.

class Solution {
public:
	int characterReplacement(string A, int K){
	    int N = A.size();
	    vector<int> F(26, 0);
	    int maxsize = 0;
	    int i=0, j=0;
	    while(j < N){
	        F[A[j] - 'A'] += 1;
	        
	        int total = 0; int maxf = 0; for(int i=0; i<26; i++){ maxf = max(maxf, F[i]); total += F[i]; }
	        total -= maxf;
	        if(total > K){ F[A[i] - 'A'] -= 1; i += 1; }
	        else maxsize = max(maxsize, (j-i+1));
	        
	        j += 1;
	    }
	    
	    return maxsize;
	}
};

// Problem Statement - 
// Link - https://practice.geeksforgeeks.org/problems/maximum-consecutive-ones/1
// You are given array nums of n length and an integer k .return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

class Solution {
  public:
    int longestOnes(int N, vector<int> &A, int K) {
        int i=0, j=0;
        int zeros = 0;
        
        int maxsize = 0;
        while(j < N){
            if(A[j] == 0) zeros += 1;
            
            if(zeros <= K) maxsize = max(maxsize, (j-i+1));
            else{ 
                if(A[i] == 0) zeros -= 1; 
                i += 1; 
            }
            
            j += 1;
        }
        
        return maxsize;
    }
};

int main(){
    Solution solve;
    
    return 0;
}