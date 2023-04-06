// BOUNDARY TRAVERSAL:
// Intuition:
// Using level order traversal, index every index on vertical basis.
// For every vertical level update the value in the map. Eventually it'll the last indexed value in the map for a specific level.
#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode * left;
    TreeNode * right;

    TreeNode(int aVal){
        val = aVal;
        left = NULL;
        right = NULL;
    }
};

//  TREE:
//            1
//          /   \
//        2       3
//      /   \    
//    4       5
//          /   \
//        6       7


class Solution{
private:
    TreeNode * createTree(){
        TreeNode * root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);
        root->left->left = new TreeNode(4);
        root->left->right = new TreeNode(5);
        root->left->right->left = new TreeNode(6);
        root->left->right->right = new TreeNode(7);

        return root;
    }

public:
    void left(TreeNode * N, vector<int> &LT){
        if(N == NULL) return;
        LT.push_back(N->val);
        left(N->left, LT);

        return;
    }

    void right(TreeNode * N, vector<int> &RT){
        if(N == NULL) return;
        RT.push_back(N->val);
        right(N->right, RT);

        return;
    }

    void leaf(TreeNode * N, vector<int> &LN){
        if(N == NULL) return;
        if(N->left == NULL && N->right == NULL) LN.push_back(N->val);
        leaf(N->left, LN);
        leaf(N->right, LN);

        return;
    }

    vector <int> bottomView(){
        TreeNode * root = createTree();

        vector<int> LT, RT, LN; //Left Traversal, Right Traversal & Leaf Node.
        left(root, LT);
        right(root, RT);
        leaf(root, LN);

        for(int i: LT) cout << i << " ";
        cout << endl;
        for(int i: RT) cout << i << " ";
        cout << endl;
        for(int i: LN) cout << i << " ";
        cout << endl;

        int nleft = LT.size();
        int nright = RT.size();
        int nleaf = LN.size();

        if(LT[nleft - 1] == LN[0]) nleft -= 1;
        if(LN[nleaf - 1] == RT[nright - 1]) nleaf -= 1;

        vector<int> boundary;
        for(int i=0; i<nleft; i++) boundary.push_back(LT[i]);
        for(int i=0; i<nleaf; i++) boundary.push_back(LN[i]);
        for(int i=(nright - 1); i>=0; i--) boundary.push_back(RT[i]);

        for(int i: boundary) cout << i << " ";
        return {};
    }

};

int main(){
    Solution solve;
    solve.bottomView();
    return 0;
}