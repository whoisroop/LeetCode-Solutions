// LeetCode -
// Description - 

#include<bits/stdc++.h>
using namespace std;

class Solution{
private:

public:
    vector <int> dijkstraPRIORITYQUEUE(int V, vector<vector<int>> A[], int source){
        vector<int> distance(V, INT32_MAX);
        distance[source] = 0;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;  //To store (distance, nValue) : Distance from source to the nValue node.
        pq.push({0, source});

        while(!pq.empty()){
            auto top = pq.top(); pq.pop();
            int nDistance = top.first, nValue = top.second;

            for(auto &i: A[nValue]){
                int neighbor = i[0], edgeW = i[1];

                if(nDistance + edgeW < distance[neighbor]){
                    distance[neighbor] = nDistance + edgeW;
                    pq.push({distance[neighbor], neighbor});
                }
            }
        }
        
        return distance;
    }

    vector <int> dijkstraSET(int V, vector<vector<int>> A[], int source){
        vector<int> distance(V, INT32_MAX);
        distance[source] = 0;
        
        set<pair<int, int>> set;
        set.insert({0, source});
        
        while(!set.empty()){
            int nDistance = (*set.begin()).first; 
            int nValue = (*set.begin()).second;
            set.erase(set.begin());
            
            for(auto &j: A[nValue]){
                int neighbor = j[0];
                int edgeW = j[1];
                
                if(nDistance + edgeW < distance[neighbor]){
                    if(distance[neighbor] != INT32_MAX) set.erase({distance[neighbor], neighbor});
                    distance[neighbor] = nDistance + edgeW;
                    set.insert({nDistance+edgeW, neighbor});
                }
            }
        }
        
        return distance;
    }
};

int main(){
    Solution solve;
    
    return 0;
}