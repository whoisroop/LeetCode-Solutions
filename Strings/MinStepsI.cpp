// GFG - Minimum steps to delete a string by deleting substring comprising of same characters.  
// Description - Given string. You are allowed to delete only some contiguous characters if all the characters are the same in a single operation. The task is to find the minimum number of operations required to completely delete the string. 

// Approach:
// How to break the strings to use DP?
// Let, the input string be ABABA: The optimal ways would be: (ABABA - ABBA - AA - "") or (ABABA - AABA - AAA - "") TOTAL STEPS: 3
// Let's appoach (ABABA - AABA - AAA - "")
// Now, to break the strings: We can remove consecutive same characters in one steps.
// Either remove an element as an individual element, or find a pair and find minimum steps to reduce the contained substring + the rightmost string, so that the resulting substring for the contained would be of the same pair of elements at the end and will take one operation to remove.
// Example - ABAC : (A) B (A) C PAIR - CONTAINED: B & RIGHTMOST: C Find minsteps required to reduce the strings (B) + (C) : 1 + 1 = 2

// A B A B A
// FIND PAIR: 
// (A) BABA         = BABA             - Individual Character
// (A) B (A) BA     = B + (A)BA        - Pair   * CHOSEN
// (A) BAB (A)      = BAB + (A)        - Pair

// PAIR: (A) B (A) BA
// PAIR the last character with the righmost substring, as there might be more consecutive characters on the right which can be removed in one operation.

// B + (A)BA    (RETURN 3)
// B : 1 RETURNED VALUE
// ABA : 2 RETURNED VALUE
// (A) BA = BA              - INDIVIDUAL 
// (A) B (A) = B + (A)      - PAIR * CHOSEN     (RETURN 2)

// B : 1 + (A) : 1 (RETURN 1 + 1)

#include<bits/stdc++.h>
using namespace std;

class Solution{
private:
    int minsteps(int i, int j, string &A){
        if(i > j) return 0;
        if(i == j) return 1;

        int N = A.size();

        int steps = 1 + minsteps(i+1, j, A);

        for(int index = i+1; index<=j; index++){
            //No Need To Add +1, The last character of pair, paired with the right substring will contibute. ABAC - B + AC - 1 + (A + C) - 1 + 1 + 1 = 3
            if(A[index] == A[i]) steps = min(steps, minsteps(i+1, index-1, A) + minsteps(index, j, A)); 
        }

        return steps;
    }

public:
    int minimumSteps(string A){
        return minsteps(0, A.size()-1, A);
    }
};

int main(){
    Solution solve;
    string A = "ababcba";
    cout << solve.minimumSteps(A) << endl;
    return 0;
}