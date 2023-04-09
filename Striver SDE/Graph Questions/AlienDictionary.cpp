// GFG: Alien Dictionary.
// Description - Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary. Find the order of characters in the alien language.

// Approach: Relative ordering can be achieved by comparing D[i] & D[i+1] dictionary words, Use topological sort to construct the proper ordering from the relative ordering. 

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    string findOrder(string D[], int N, int K) {
        vector<vector<int>> A(K);
        for(int i=0; i<N-1; i++){
            string a = D[i], b = D[i+1];
            int size = min(a.size(), b.size());
            
            int j=0;
            while(j<size && a[j] == b[j]) j+=1;
            if(j == size) continue;
            
            A[a[j]-'a'].push_back(b[j]-'a');
        }
        
        // TOPO SORT:
        vector<int> indegree(K);
        for(int i=0; i<K; i++){
            for(int &neighbor: A[i]) indegree[neighbor] += 1;
        }
        
        queue<int> q;
        for(int i=0; i<K; i++) if(indegree[i] == 0) q.push(i);
        
        string order = "";
        while(!q.empty()){
            int nValue = q.front(); q.pop();
            
            for(int &neighbor: A[nValue]){
                indegree[neighbor] -= 1;
                if(indegree[neighbor] == 0) q.push(neighbor);
            }
            
            order += ('a' + nValue);
        }
        
        return order;
        
    }
};

int main(){
    Solution solve;
    
    return 0;
}