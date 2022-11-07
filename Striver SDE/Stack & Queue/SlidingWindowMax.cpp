// LeetCode - 239. Sliding Window Maximum.
// - Brute force
// We can write a nested loop, the outer loop goes through each window and the inner loop finds the max within the window. This is O(N^2) time complexity.

// To optimize on brute force, we can either reduce outer or inner loop complexity. Since we have to examine each element at least once (there's no way to find the maximum if we don't know what the values are..), there is not much we can do for outer loop. So we have to work on the inner loop.

// - Preserving inner elements maximum
// Currently, to get the max of the sliding window, we look at each element in the window and compare them. Analogous to sliding window sum problem (given an array and a window size, return the sum of each window), when a window slides, only two elements change - the leftmost gets removed and a new element gets added to the right. Everything in the middle (let's call them "inner elements") is unchanged, and the maximum element among these inner elements are unchanged as well. The key to reducing inner loop complexity is to persist the maximum of the inner elements as we slide the window. Ideally, we want to be able to access the maximum element in less than O(N) time and updating it in less than O(N) time.

// - Balanced binary search tree
// One way to achieve this goal is to save the window elements in a self-balancing binary search tree. Because it's self-balancing, the depth of the tree is guaranteed to be O(log(N)) so lookup, getting max, insert and delete are all O(log(N)) operations. Every time we slide the window, we remove the node that's out of the window and add the one that comes into the window to the tree. Overall, this gives us O(N log(k)) since the number of tree nodes is k and we slide max N times.

// This is pretty good already, but can we do better?

// - Larger elements entering window invalidates smaller elements
// A question we can ask ourselves is "do we need to keep all the window elements in our state?".
// An important observation is for two elements arr[left] and arr[right], where left < right, arr[left] leaves the window earlier as we slide. If arr[right] is larger than arr[left], then there is no point keeping arr[left] in our state since arr[right] is always gonna be larger during the time arr[left] is in the window. Therefore, arr[left] can never be the maximum.

// - Monotonic deque
// Here we introduce an interesting data structure. It's a deque with an interesting property - the elements in the deque from head to tail are in decreasing order (hence the name monotonic).

// To achieve this property, we modify the push operation so that

// Before we push an element into the deque, we first pop everything smaller than it out of the deque.

// This enforces the decreasing order.

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    deque<int> q;   //Double Ended Queue
    void push(int value){
        while(!q.empty() && q.front() < value) q.pop_front();
        q.push_back(value);
    }

    vector<int> slidingWindow(vector<int> &A, int wsize){
        int n = A.size();
        int i=0, j=0; 
        vector<int> windowMax;

        while(j<n){
            push(A[j]);

            if((j-i+1) == wsize){
                windowMax.push_back(q.front());

                if(q.front() == A[i]) q.pop_front();
                i++;
            }
            j++;
        }

        return windowMax;
    }
};