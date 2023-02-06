// LeetCode - 987. Vertical Order Traversal of a Binary Tree
// Description - 

#include<bits/stdc++.h>
using namespace std;

struct compare{
 bool operator()(pair<int, int> &A, pair<int, int> &B){
     if(A.first == B.first) return (A.second > B.second);
     return (A.first < B.first);
 }
};

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root == NULL) return {};
    
        map<int, vector<int>> vmap;
        queue<pair<TreeNode *, int>> q;
        
        q.push({root, 0});
        while(!q.empty()){
            int n = q.size();
            priority_queue<pair<int, int>, vector<pair<int, int>>, compare> maxheap;   //Index - Value

            for(int i=0; i<n; i++){
                auto front = q.front(); q.pop();
                TreeNode * node = front.first; int index = front.second;
                
                maxheap.push({index, node->val});
                if(node->left) q.push({node->left, index-1});
                if(node->right) q.push({node->right, index+1});
            }

            while(!maxheap.empty()){
                vmap[maxheap.top().first].push_back(maxheap.top().second);
                maxheap.pop();
            }
        }
        
        vector<vector<int>> vertical;
        for(auto &i:vmap) vertical.push_back(i.second);
        return vertical; 
    }
};

int main(){
    Solution solve;
    
    return 0;
}