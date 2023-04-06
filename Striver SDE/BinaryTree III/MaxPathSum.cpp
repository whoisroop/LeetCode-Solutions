// LeetCode - Maximum Path Sum From Any Node.
// Description - 

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    //Function to return maximum path sum from any node in a tree.
    int pathsum(Node * node, int &maxsum){
        if(node == NULL) return 0;
        
        int pathA = pathsum(node->left, maxsum);
        int pathB = pathsum(node->right, maxsum);
        
        maxsum = max(maxsum, max(0, max(pathA, pathB)) + node->data);
        maxsum = max(maxsum, pathA+pathB+node->data);  //Max of left + right or a single node encountered.
        return max(0, max(pathA, pathB)) + node->data;  //Continue either of path or create a new one.
    }
    int findMaxSum(Node* root){
        int maxsum = INT32_MIN;
        pathsum(root, maxsum);
        return maxsum;
    }
};

int main(){
    Solution solve;
    
    return 0;
}