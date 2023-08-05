// Problem - Root to leaf paths sum 
// Link - https://practice.geeksforgeeks.org/problems/root-to-leaf-paths-sum/1

#include<bits/stdc++.h>
using namespace std;

long long treePathsSum(Node * root){
    if(root == NULL) return 0;
    // Level Order Traversal: BFS
    // Queue
    queue<pair<Node *, long long int>> q;
    q.push({root, root->data});
    
    long long int sum = 0;
    while(q.empty() != true){
        int N = q.size();
        for(int i=0; i<N; i++){
            auto top = q.front(); q.pop();
            Node * current = top.first;
            long long value = top.second;
            
            if(current->left == NULL && current->right == NULL) sum += value;
            
            if(current->left) q.push({current->left, value*10 + current->left->data});
            if(current->right) q.push({current->right, value*10 + current->right->data});
        }
    }
    
    return sum;
}

int main(){
    Solution solve;
    
    return 0;
}