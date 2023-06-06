// GFG: Account Merge 
// Description: https://practice.geeksforgeeks.org/problems/account-merge/1
// Approach: 
// Example: 
// [
// ["John","johnsmith@mail.com","john_newyork@mail.com"],
// ["John","johnsmith@mail.com","john00@mail.com"],
// ["Mary","mary@mail.com"],
// ["John","johnnybravo@mail.com"]
// ]

// The elements of an account belongs together i.e. ACCOUNT[i][0 1 ...], form an ABSTRACT Node.
// The ["johnsmith@mail.com","john_newyork@mail.com"] is represented as a single node or NODE ZERO (index: 0).
// All the elements or the mails are assigned to the node using hashmap.
// When to connect two ABSTRACT NODE? When there is a common email.
// When assigning the emails to nodes, if a common email is already found assigned to some other node, connect the node to which the email belongs to and the current node.
// Now traverse through the hashmap, find the ultimate parent of emails & group them together.

#include<bits/stdc++.h>
using namespace std;

class UnionFind{
private:
    vector<int> parent, size;
public:
    UnionFind(int N){
        parent.resize(N+1);
        size.resize(N+1);

        for(int i=0; i<=N; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    // Ultimate Parent:
    int findparent(int nValue){ 
        if(parent[nValue] == nValue) return nValue;

        return parent[nValue] = findparent(parent[nValue]); //Path Compression
    }

    // Union By Size
    void connect(int u, int v){
        int uparentU = findparent(u);
        int uparentV = findparent(v);

        if(uparentU == uparentV) return;

        if(size[uparentU] <= size[uparentV]){
            parent[uparentU] = uparentV;
            size[uparentV] += size[uparentU];
        }
        else{
            parent[uparentV] = uparentU;
            size[uparentU] += size[uparentV];
        }

        return;
    }

};

class Solution{
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &A) {
        int N = A.size();
        UnionFind dset(N);  //The clusters are represented as node.
        // Condition to join two cluster: When there is a common email. USE MAP.
        
        unordered_map<string, int> emap;    //Map the email to node.
        for(int i=0; i<N; i++){
            int size = A[i].size();
            for(int j=1; j<size; j++){
                string email = A[i][j];
                if(emap.count(email) != 0) dset.connect(i, emap[email]);
                
                emap[email] = i;    //Belongs To NODE CLUSTER.
            }
        }
        
        unordered_map<int, vector<string>> mailgroup;
        for(auto &i: emap){
            int parent = dset.findparent(i.second); //Find parent of current node.
            mailgroup[parent].push_back(i.first);   //Assign the email to parent node. Or the cluster.
        }
        
        vector<vector<string>> solution;
        for(auto &i: mailgroup){
            i.second.push_back(A[i.first][0]);
            sort(i.second.begin(), i.second.end());
            
            solution.push_back(i.second);
        }
        
        return solution;
    }
};

int main(){
    Solution solve;
    
    return 0;
}