// LeetCode - 295. Find Median Of Data Steam.
// The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.

// For example, for arr = [2,3,4], the median is 3.
// For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
// Implement the MedianFinder class:
 
// MedianFinder() initializes the MedianFinder object.
// void addNum(int num) adds the integer num from the data stream to the data structure.
// double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.

// APPROACH:
// Here, we are paritioning the values into two parts: 1 2 (3) 4 5 : Left parition containing elements < median & Right partition containing elements > median.
// How to accomplish? In order to maintain balance i.e. in terms of number of elements in each partition the max difference can be of one.
// We will compare the incoming element with the max of left partition (Top Of MaxHeap) & if the element is < (Top Of MaxHeap) push it into the left else into the right partition.
// After insertion check the size of elements in each partition. If the size differs greater than one: Shift the max from left to right or min from right to left.
// For odd terms the median will be in the parition containing one greater element.
// Otherwise it'll be the max of left & min of right.

#include<bits/stdc++.h>
using namespace std;

class MedianFinder {
public:
    priority_queue<int> maxheap; //Left Partition (MAX HEAP)
    priority_queue<int, vector<int>, greater<int>> minheap; //Right Partition (MIN HEAP)
    
    MedianFinder() {
        
    }
    
    void addNum(int value) {
        if(maxheap.empty() || value <= maxheap.top()) maxheap.push(value);
        else minheap.push(value);
        
        //Manage the halves:
        if(maxheap.size() > minheap.size() + 1){
            minheap.push(maxheap.top());
            maxheap.pop();
        }
        else if(minheap.size() > maxheap.size() + 1){
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }
    
    double findMedian() {
        if(maxheap.size() > minheap.size()) return maxheap.top();
        if(minheap.size() > maxheap.size()) return minheap.top();
        
        return (1.0*maxheap.top() + 1.0*minheap.top())/2;
    }
};