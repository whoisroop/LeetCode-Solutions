#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isPalindrome(string &s, int i, int j){
        while(i<j){
            if(s[i]!=s[j])  return false;
            i++;    j--;
        }

        return true;
    }
    
    void f(int i, int li, string &s, vector<string> sequence, vector<vector<string>> &sol){
        
        if(i==li+1){
            sol.push_back(sequence);
            return;
        }
        
        for(int j=i; j<=li; j++){
            if(isPalindrome(s, i, j)){
                string sub = s.substr(i, (j-i+1));
                sequence.push_back(sub);
                f(j+1, li, s, sequence, sol);
                sequence.pop_back();
            }
        }
        
        return;
    }
    
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> solution;
        vector<string> sequence;
        int li = s.size()-1;
        
        f(0, li, s, sequence, solution);

        for(auto &i: solution){
            for(auto &j: i) cout << j << " ";
            cout << endl;
        }

        return solution;
        
    }
};

int main(){
    string s = "aabb";
    Solution newSol;
    newSol.partition(s);

    return 0;
}