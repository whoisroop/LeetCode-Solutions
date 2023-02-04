// LeetCode - 767. Reorganize String
// Description - 
// Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.
// Return any possible rearrangement of s or return "" if not possible.

#include<bits/stdc++.h>
using namespace std;

class Solution{
private:

public:
    string reorganize(string & str){
        int n = str.size();
        vector<int> fmap(26, 0);

        for(int i=0; i<n; i++) fmap[(str[i]-'a')] += 1;

        priority_queue<pair<int, char>> pq; //Max Priority Queue: <Frequency, Letter>
        for(int i=0; i<26; i++) if(fmap[i] != 0) pq.push({fmap[i], (i + 'a')});

        string s = "";
        while(pq.empty() != true){
            if(pq.size() == 1 && pq.top().first > 1) return "";

            auto top = pq.top(); pq.pop();
            s += top.second;

            if(pq.empty() != true){
                auto next = pq.top(); pq.pop();
                s += next.second;

                if(next.first != 1) pq.push({ next.first - 1, next.second });
            }

            if(top.first != 1) pq.push({ top.first - 1, top.second });
        }

        return s;
    }
};

int main(){
    Solution solve;
    string str = "vvvlo";
    cout << solve.reorganize(str);
    
    return 0;
}