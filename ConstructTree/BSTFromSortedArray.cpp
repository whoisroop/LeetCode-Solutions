// LeetCode - 108. Convert Sorted Array to Binary Search Tree.
// Description - Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

#include<bits/stdc++.h>
using namespace std;

class Solution{
private:

public:
    TreeNode * createBST(int start, int end, vector<int> &A){
        if(start > end) return NULL;

        int midpoint = (start + end)/2;
        TreeNode * node = new TreeNode(A[midpoint]);

        node->left = createBST(start, midpoint - 1, A);
        node->right = createBST(midpoint + 1, end, A);
        return node;
    }

    TreeNode* sortedArrayToBST(vector<int> &A) {
        return createBST(0, A.size()-1, A);
    }
};

int main(){
    Solution solve;
    
    return 0;
}