// Problem - Sum Tree
// Link - https://practice.geeksforgeeks.org/problems/sum-tree/1?page=1&category[]=Tree&sortBy=submissions
// Description - Sum of all the nodes of the left subtree + Sum of all the nodes of right subtree = parent node value. Check for a binary tree.

// Approach:
// We need to return two values in the recursion process: The sum of child nodes, Check if the subtree are sum tree. (SUM VALUE, Boolean)
// Declare another class with the required parameters, return that from the function.

#include<bits/stdc++.h>
using namespace std;

class bi{
public:
    bool state;
    int sum;
    
    bi(bool aState, int aSum){ state=aState; sum=aSum; }
};

class Solution{
private:
    bi sum(Node * node){
        if(node == NULL) return bi(true, 0);
        if(node->left == NULL && node->right == NULL) return bi(true, node->data);
        
        bi L = sum(node->left);
        if(L.state == false) return bi(false, -1);
        
        bi R = sum(node->right);
        if(R.state == false) return bi(false, -1);
        
        if(node->data != L.sum + R.sum) return bi(false, -1);

        return bi(true, node->data + L.sum + R.sum);
    }
    
public:
    bool isSumTree(Node * node){
        bi A = sum(node);
        return A.state;
    }
};

int main(){
    Solution solve;
    
    return 0;
}