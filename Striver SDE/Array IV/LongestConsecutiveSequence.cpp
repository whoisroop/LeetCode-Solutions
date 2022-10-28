// LeetCode - 128. Longest Consecutive Sequence.
// Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
// You must write an algorithm that runs in O(n) time.

#include <bits/stdc++.h> 
using namespace std;

// Approach:
// Think of it like creating a chain of (with each element as a magnet), i.e. each ith element will either attach to either side (Left Or Right) of any existing chain OR create a new.
// If attached to an existing chain, update the length of chain to both of its ends: As the size of new chain will be: Size Of LEFT Chain (STORED AT ENDS) + Size Of RIGHT Chain (STORED AT ENDS) + 1.
// How to check for left chain size: 
// As the chain contains consecutive elements: Check if (A[i] - 1) element exists for an element (A[i]).
// If it does, the chain length is stored at map[A[i]-1]:
// New Chain Length = map[A[i]-1] + 1 (For A[i])
// The chain ends are: Right A[i] & Left end can be determined with the use of chain length: A[i] - map[A[i]-1] OR (A[i] - LENGTH + 1)
// Update The Chain Lengths At Both Ends: map[A[i]] = Length & map[A[i] - map[A[i]-1]] = Length 

class Solution {
public:
    int longestConsecutive(vector<int> &A) {
        int n = A.size();

        unordered_map<int, int> mpp;   //To store size of consecutive sequence.
        int length = 0;

        for(int &i: A){
            if(mpp.find(i) != mpp.end()) continue;    //If Already Present: Duplicate Case.
            mpp[i] = 1; //Initialize with ones.
            int total = 1;  //Length Of Sequence.

            if(mpp.find(i-1) != mpp.end() && mpp.find(i+1) != mpp.end()){ //Both Part
                total = mpp[i-1] + mpp[i+1] + 1;

                // mpp[i-1] : Length of already formed consecutive sequence (i is inserted on its right end).
                // Leftmost element = i - mpp[i-1], As the elements are consecutive & left part contains mpp[i-1] elements.
                // Update both the ends of the sequence.
                mpp[i - mpp[i-1]] = total;
                mpp[i + mpp[i+1]] = total;
            }
            else if(mpp.find(i-1) != mpp.end()){    //Only Left
                // Here one of the ends will be the element itself as only left sequence part exists.
                total = mpp[i-1] + 1;
                mpp[i - mpp[i-1]] = total;
                mpp[i] = total;
            }
            else if(mpp.find(i+1) != mpp.end()){    //Only Right
                total = mpp[i+1] + 1;
                mpp[i + mpp[i+1]] = total;
                mpp[i] = total;
            }

            length = max(length, total);
        }
        
        return length;
    }
};