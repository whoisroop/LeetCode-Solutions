#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> dataLocation(vector<int> location, vector<int> from, vector<int> to){
        unordered_set<int> iset;
        for(int &i: location) iset.insert(i);

        int n = from.size();
        for(int i=0; i<n; i++){
            iset.erase(from[i]);
            iset.insert(to[i]);
        }

        vector<int> solution;
        for(int i: iset) solution.push_back(i);

        sort(solution.begin(), solution.end());
        return solution;
    }

};

int main(){
    vector<int> location = {1,5,2,6};
    vector<int> from = {1,4,5,7};
    vector<int> to = {4,7,1,3};

    Solution find;
    vector<int> solution = find.dataLocation(location, from, to);
    for(int i: solution) cout << i << " ";
    return 0;
}