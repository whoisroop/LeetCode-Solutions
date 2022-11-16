// GFG - Allocate Minimum Number Of Pages.

// You are given N number of books. Every ith book has Ai number of pages. 
// You have to allocate contiguous books to M number of students. There can be many ways or permutations to do so. In each permutation, one of the M students will be allocated the maximum number of pages. Out of all these permutations, the task is to find that particular permutation in which the maximum number of pages allocated to a student is the minimum of those in all the other permutations and print this minimum value.
// Each book will be allocated to exactly one student. Each student has to be allocated at least one book.

// Approach:
// Here, we apply the binary search on answer & check for the given predicted value i.e. the max pages that can be allocated to a single person and count the number of persons for total distribution considering upper bound to be the predicted MIDPOINT.
// If the number of people required are lesser than the given, the upper bound can be decreased and vice versa.
// Find the minimum value that satisfies the condition of division among M persons.


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int validAllocation(int A[], int n, int maxLimit, int students){
        int counter = 1; int sum = 0;

        for(int i=0; i<n; i++){
            if(A[i] > maxLimit) return false;   //Important EdgeCase
            
            if((sum+A[i]) <= maxLimit) sum+=A[i];
            else{
                sum = A[i]; counter++;
            }
        }

        return (counter<=students);
    }

    int findPages(int A[], int n, int students) {
        if(students > n) return -1;
        
        int i=0, j=INT32_MAX;

        int midpoint;
        while(i<=j){
            midpoint = (i + (j-i)/2);
            
            if(validAllocation(A, n, midpoint, students)) j=midpoint-1; //Check for the predicted upper bound if the division required M persons or less.
            else i=midpoint+1;
        }
        
        return i;
    }
};