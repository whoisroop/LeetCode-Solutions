// LeetCode -
// Description - 

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countSpecialNumbers(int N, vector<int> A) {
        sort(A.begin(), A.end());
        
        int maxV = A[A.size() - 1];
        int n = maxV + 1;
        vector<int> pf(maxV + 1, 0);
        for(int i=2; i<n; i++){
            if(!pf[i]){
                for(int j=i; j<n; j+=i) if(!pf[j]) pf[j] = i;
            }
        } pf[1] = 1;
        
        unordered_map<int, int> visited; // Value & Frequency
        int counter = 0;
        for(int i=0; i < N; i++){
            if(i < N && A[i] == A[i + 1]){
                while(i < N-1 && A[i] == A[i+1]){ visited[A[i]] += 1; i += 1; }
                visited[A[i]] += 1; continue;
            }
            
            int value = A[i];
            while(pf[value] != value){
                if(visited.find(pf[value]) != visited.end() && visited[pf[value]] >= 1){ counter += 1; break; }
                value = value/pf[value];
            }
            
            visited[value] += 1;
        }
        cout << "!!!" << counter << endl;
        for(auto &i: visited){ counter += (i.second - 1); cout << i.first << " - " << i.second << endl; }
        
        return counter;
    }
};

int main(){
    Solution solve;
    
    return 0;
}