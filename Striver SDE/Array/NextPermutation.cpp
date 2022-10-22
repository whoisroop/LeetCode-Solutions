// LeetCode - 31. Next Permutation.

#include<bits/stdc++.h>
using namespace std;

// Algorithm:
// 1. Traverse the array from right to left and find the first element which is smaller than its previous element.
//  4 2 0 (2) 3 2 0
// 2. Find the smallest element greater than the element on its right half.
//  4 2 0 (2) | (3) 2 0
// 3. Swap the elements.
//  4 2 3 | 2 2 0
// 4. Sort the right half. (Reversing the right half will also do.)
//  4 2 3 0 2 2

class Solution{
public:
    void findNext(vector<int> &array){
        int n = array.size();
        
        //Find the breaking point.
        int index = -1;
        for(int i=(n-2); i>=0; i--){
            if(array[i]<array[i+1]) {index = i; break;}
        }
        
        if(index == -1){
            reverse(array.begin(), array.end());
            return;
        }
        
        //Find the smallest element greater than ith element in the right half.
        int ns = -1; //Next Smaller
        for(int i=(n-1); i>=(index+1); i--){
            if(array[i] > array[index]){
                if(ns == -1) ns = i;
                else{
                    if(array[i] < array[ns]) ns = 1;
                }
            }
        }

        swap(array[index], array[ns]);
        reverse(array.begin() + (index+1), array.end());

        return;
    }
};