// LeetCode - 75. Sort Color.
// Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

// Solution:
// DUTCH FLAG ALGORITHM -
// Dutch flag consist of three colors : RED WHITE BLUE. Assume the color are divided into thin stripes and jumbled around.
// Now, the RED should be on top, White in middle & Blue at the bottom.
// Consider two pointers: One pointing at the topmost stripe pointerA & other at the bottom most stripe pointerB.
// Start the traversal of stripes from top to bottom: 
// Whenever you encounter a RED stripe, replace the RED stripe with the topmost stripe and point the pointerA to the second stripe from top.
// In this way all the stripes above pointerA are RED.
// Similarly, whenever you encounter a BLUE stripe, replace the BLUE stripe with the bottom most stripe and point the pointerB to the second stripe from bottom.
// In this way all the stripes below pointerB are BLUE.
// Repeat the algorithm until the bottom most pointer is reached.

#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    void sortABC(vector<int> &array){
        int n = array.size();
        int top = (n-1);    // TOP : 2
        int bottom = 0;     // BOTTOM : 0

        cout << "ARRAY: ";
        for(int i: array) cout << i << " ";
        cout << endl;

        int i = bottom;
        while(i<=top){
            if(array[i] == 0){
                swap(array[i], array[bottom]); 
                i++; bottom++;  //Why i++? At certain edge cases: (i == bottom), hence we'll enter infinite loop. {0,0,1,0}
            }
            else if(array[i] == 2){
                swap(array[i], array[top]);
                top--;
            }
            else i++;
        }

        cout << "DUTCH SORT: ";
        for(int i: array) cout << i << " ";

        return;
    }
};

int main(){
    Solution find;
    vector<int> array = {0,2,2,1,0,2,1,1};

    find.sortABC(array);
    return 0;
}