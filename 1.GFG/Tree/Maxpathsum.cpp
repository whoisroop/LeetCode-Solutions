// Problem - Max Path Sum
// Link - https://practice.geeksforgeeks.org/problems/maximum-path-sum/1?page=1&category[]=Tree&sortBy=submissions

// Find the max path sum between two leaf nodes.
// Carry the sum from left & right leaf and check at pivot if it's the max value.

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int minmin = -1e8;
    int maxsum(Node * current, int &maxV){
        if(current->left == NULL && current->right == NULL) return current->data;
        
        int L = minmin;
        int R = minmin;
        if(current->left) L = maxsum(current->left, maxV);
        if(current->right) R = maxsum(current->right, maxV);
        
        maxV = max(maxV, L + R + current->data);
        return current->data + max(L, R);
    }
    
public:
    int maxPathSum(Node* root){
        if(root == NULL) return 0;
        
        int maxV = minmin;
        int tillroot = maxsum(root, maxV);
        if(root->left == NULL || root->right == NULL) maxV = max(tillroot, maxV);
        return maxV;
    }
};

int main(){
    Solution solve;
    
    return 0;
}