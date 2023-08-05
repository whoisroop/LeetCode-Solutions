#include<bits/stdc++.h>
using namespace std;

// Problem - 
// Description - Find the longest increasing subsequence & print the subsequence.

// Approach:

// Questions based on LIS:
// 1. Find Length Of LIS
// 2. Print LIS
// 3. Count Number Of LIS's
// 4. Count All LIS's

// * Find Length : O(NlogN) Binary Search Approach
// Replace values on the existing sequence to create one with maximum size:
// {6, 5, 7, 3}
// 6 - Replace 6 With 5, as the values greater than 5 will indeed be greater then 6 & will yeild a greater sequence length.
// 5 - Add the value to the list, (5, 7) equivalent to (6, 7).
class Solution {
public:
    int LIS(int H[], int N) {
        vector<int> A(N, INT32_MAX);
        for(int i=0; i<N; i++){
            int index = (lower_bound(A.begin(), A.end(), H[i]) - A.begin());
            A[index] = H[i];
        }
        
        int counter = 0;
        while(counter < N && A[counter] != INT32_MAX) counter += 1;
        return (N-counter);
    }
};

// * Print LIS:
// Using DP: Do not think of it as DP, we store the length of longest increasing subsequence ends at index 'i' at DP[i].
// If we get a value A[j] > A[i], DP[j] = DP[i] + 1; Make sure the subsequence we're choosing yeilds the maximum length.
// The new element A[j] is added to the sequence, to print the LIS keep track of the previous element indexes.
// Create & store a parent vector to store the indexe of the value of the sequence to which the current element is added.

// ARRAY:  1 4 2 3
// PARENT: 0 1 2 3
// DP:     1 1 1 1

// Move to 4, check for all the previous elements if(element before < current element) & check the size of the sequence.
// If the current element is added to the sequence & it yeilds the maximum LIS ending at ith index, store the index of previous to the parent of current. 

// After iteration ends:
// ARRAY:   1 4 2 3
// PARENT:  0 1 1 2
// DP:      1 2 2 3
// The maxsize subsequence increasing ends at index 3, backtrack from the index to print LIS using parent vector.

// Problem - Print LIS
// Link - https://practice.geeksforgeeks.org/problems/printing-longest-increasing-subsequence/0

class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int N, vector<int> &A) {
        vector<int> DP(N, 1);
        vector<int> parent(N, 0); for(int i=0; i<N; i++) parent[i] = i;
        
        int maxsize = 0;
        int index = 0;
        for(int i=0; i<N; i++){
            for(int j=0; j<i; j++){
                if(A[j] < A[i] && DP[j] + 1 > DP[i]){ 
                    DP[i] = DP[j] + 1; 
                    parent[i] = j;
                }
            }
            
            if(DP[i] > maxsize){ maxsize = DP[i]; index = i; }
        }
        
        vector<int> solution; 
        // Back Track:
        while(index != parent[index]){ 
            solution.push_back(A[index]); 
            index = parent[index];
        } solution.push_back(A[index]);
        
        reverse(solution.begin(), solution.end());
        return solution;
    }
};

// Problem - Largest Divisible Subset
// Link - https://practice.geeksforgeeks.org/problems/e866d887f78664cdbf24c61ef9404691f4fb9e59/0

// Largest divisible subset, the value of current element to be added depends on the elements in the subsequence or the greatest element in the subsequence if it divides the current value all the other elements in the subsequence or subset divides the current value, hence add it to the subset.
// {a, b, c} a < b < c & a%b == b%c == a%c == 0
// If c % value == 0, it suggests that all the other elements also divides value.

class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int N, vector<int> &A) {
        vector<int> DP(N, 1);
        vector<int> parent(N, 0); for(int i=0; i<N; i++) parent[i] = i;
        
        int maxsize = 0;
        int index = 0;
        for(int i=0; i<N; i++){
            for(int j=0; j<i; j++){
                if(A[j] < A[i] && DP[j] + 1 > DP[i]){ 
                    DP[i] = DP[j] + 1; 
                    parent[i] = j;
                }
            }
            
            if(DP[i] > maxsize){ maxsize = DP[i]; index = i; }
        }
        
        vector<int> solution; 
        // Back Track:
        while(index != parent[index]){ 
            solution.push_back(A[index]); 
            index = parent[index];
        } solution.push_back(A[index]);
        
        reverse(solution.begin(), solution.end());
        return solution;
    }
};

// * Count Number Of LIS
// Declare a vector counter, to count the number of ways the largest LIS i.e. DP[i] can be created ending at index 'i' in the counter vector.
// When the iterations are over, for the maxlength increasing subsequence, sum all the ways.

// ARRAY:   3 4 9 2 6
// DP:      1 1 1 1 1
// Count:   1 1 1 1 1

// Iteration: INDEX - 2
// Index:   0 1  2  3 4
// ARRAY:   3 4 (9) 2 6
// DP:      1 2  1  1 1
// Count:   1 1  1  1 1
// The value A[0] < A[2]: DP[2] = DP[0] + 1; Count[2] = Count[0]
// The value A[1] < A[2]: DP[2] = DP[1] + 1; Count[2] = Count[1]

// Index:   0 1  2  3 4
// ARRAY:   3 4 (9) 2 6
// DP:      1 2  3  1 1
// Count:   1 1  1  1 1

// If there was some other increasing subsequence of length DP[i] < DP[j] such that the DP[i] + 1 == DP[j]; Add the number of ways for this subsequence too to the counter, as the value can also be added to current subsequence to yeild longest increasing subsequence ending at j of size DP[j].

class Solution{
    public:
    int NumberofLIS(int N, vector<int> &A) {
        vector<int> DP(N, 1);
        vector<int> count(N, 1);
        
        for(int i=0; i<N; i++){
            for(int j=0; j<i; j++){
                if(A[j] < A[i]){
                    if(DP[j] + 1 < DP[i]);
                    else if(DP[j] + 1 == DP[i]) count[i] += count[j];
                    else{
                        DP[i] = DP[j] + 1;
                        count[i] = count[j];
                    }
                }
            }
        }
        
        int maxlength = 0; for(int i=0; i<N; i++) maxlength = max(maxlength, DP[i]);
        int total = 0; for(int i=0; i<N; i++) if(DP[i] == maxlength) total += count[i];
        
        return total;
    }
};

// * Count All LIS:
// Counting Pattern - 
// {1, 2, 3} if all the subsets are itself a solution, total solution = 2^n.
// But we need to calculate all the increasing subsequence, not the subsets of longest one, its only a part of solution.
// Assume we have the total number of solutions for the subsequence {1, 2, 3} i.e. {1, 2, 3, (1,2), (2,3), (1,3), (1,2,3)} = 7 (N).
// Let's add a new member to the subset - 4.
// The value 4 will generate new solution in addition to exisiting ones, i.e. add the new value to all the current subsets, it'll yeild a correct solution (N) + the exisiting solution (N) + 1 (The new value alone)
// N + N + 1 : Total += (Total + 1)

// Add the new value to all the existing subsets + existing subsets + start a new subset with the value.

// {1, 2, 3, 4} : {1, 2, 3, (1,2), (2,3), (1,3), (1,2,3)} + {(1,4), (2,4), (3,4), (1,2,4), (2,3,4), (1,3,4), (1,2,3,4)} + {4}

// Problem - Count AP Subsequences
// Link - https://practice.geeksforgeeks.org/problems/count-of-ap-subsequences0016/0

class Solution{
public:
    long long int count(int N, int A[]){
        vector<unordered_map<int, int>> DP(N);  // DP[Index][Difference] : Gives the length of LIS (Longest AP Subsequence) ending at index 'i' with difference 'D'

        long long int counter = N+1;    // All the single elements & null subsequence are AP.
        for(int j=1; j<N; j++){
            for(int i=0; i<j; i++){
                int D = A[j] - A[i];    // Calculate Difference
                
                int L = 0;
                if(DP[i].count(D) != 0) L = DP[i][D];   // Check the length of AP ending at ith index with difference 'D'
                
                DP[j][D] += L+1;    // Increment the total solutions & save it for further elements
                counter += L+1;     // Add to the counter for total solution
            }
        }
        
        return counter;
    }
};

int main(){
    Solution solve;
    
    return 0;
}