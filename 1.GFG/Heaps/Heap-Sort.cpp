// Problem - Heap Sort
// Link - https://practice.geeksforgeeks.org/problems/heap-sort/0

// Heap Data Structure:
// Heap is a complete binary tree (all the levels except last is filled & node at last level are at left).
// Heap binary tree is represented & stored using arrays, the parent element index, L = 2*index+1 & R = 2*index+2 ; Parent = (index-1)/2
// We take three connected nodes, L R & current and make sure the current or the parent node holds the max value, incase of maxheap.
// Whenever, the value is swapped between parent & child node, the value swapped (parent) might be smaller than the value of the current children of swapped parent, hence make sure the heapify operation is performed recursively on the parent node that became child & is at the correct position or level (sink).

// To create a heap, start from the bottom, compare every node (parent) & its children (L & R) and make sure the parent holds the greatest value.
// Heap sort? 
// One property to notice is when root is replaced with a random value, the random value sinks down to its correct position in (logN) time & size of tree is decreased.
// Using the property, the root is extacted i.e. swapped with the last element, the size of the tree is decreased by 1.
// It's performed repeatedly.

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    //Heapify function to maintain heap property.
    void heapify(int A[], int N, int current){
        int L = 2*current+1;
        int R = 2*current+2;
        
        int maxindex = current;
        if(L < N && A[L] > A[maxindex]) maxindex = L;
        if(R < N && A[R] > A[maxindex]) maxindex = R;
        
        if(maxindex != current){
            swap(A[maxindex], A[current]);
            heapify(A, N, maxindex);
        }
        
        return;
    }

    //Function to build a Heap from array.
    void buildHeap(int A[], int N){
        for(int i=N-1; i>=0; i--) heapify(A, N, i); 
        
        return;
    }
    
    //Function to sort an array using Heap Sort.
    void heapSort(int A[], int N){
        buildHeap(A, N);
        
        for(int i=N-1; i>=0; i--){
            swap(A[0], A[i]);
            heapify(A, i, 0);
        }
        
        return;
    }
};

int main(){
    Solution solve;
    
    return 0;
}