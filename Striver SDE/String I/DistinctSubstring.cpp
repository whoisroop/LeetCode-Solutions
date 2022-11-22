// GFG: Find Number Of Distinct Substring Of Size K.

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int distinct(string s){
        int n = s.size();
        unordered_set<string> vset; //Visited Set!
        for(int i=0; i<(n-1); i++){
            string substring = ""; 
            substring += s[i]; substring += s[i+1];
            vset.insert(substring);
        }

        return vset.size();
    }
};

int main(){
    Solution find;
    cout << find.distinct("WLRBBMQBHCDARZOWKKYHIDDQSCDXRJMO");
    return 0;
}