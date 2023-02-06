// Alexa is given n piles of equal or unequal heights. 
// In one step, Alexa can remove any number of boxes from the pile which has the maximum height and try to make it equal to the one which is just lower than the maximum height of the stack. Determine the minimum number of steps required to make all of the piles equal in height.

// EXAMPLE:
// Input  : [1, 1, 2, 2, 2, 3, 3, 3, 4, 4]
// Output : 15
// After sorting in reverse, we have...
// [4, 4, 3, 3, 3, 2, 2, 2, 1] --> (2 steps to transform the 4's) --> The 3's must wait for 2 numbers before it to finish their reduction
// [3, 3, 3, 3, 3, 2, 2, 2, 1] --> (5 steps to transform the 3's) --> The 2's must wait for 5 numbers before it to finish their reduction
// [2, 2, 2, 2, 2, 2, 2, 2, 1] --> (8 steps to transform the 2's) --> The 1's must wait for 8 numbers before it to finish their reduction
// [1, 1, 1, 1, 1, 1, 1, 1, 1, 1]

// Count numbers in reverse sorted array when a number just smaller is encountered.

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int steps(vector<int> &pile){
        int n = pile.size();
        sort(pile.begin(), pile.end(), greater<int>());

        int step = 0;
        for(int i=0; i<n; i++){
            if(i == 0) continue;
            if(pile[i] != pile[i-1]) step += i;
        }

        return step;
    }
};

int main(){
    Solution find;
    vector<int> p = {1,1,2,2,2,3,3,3,4,4};
    cout << find.steps(p);
    return 0;
}