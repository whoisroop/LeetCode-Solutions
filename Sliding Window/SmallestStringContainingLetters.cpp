// GFG - Smallest window in a string containing all the characters of another string.
// Description - Given two strings S and P. Find the smallest window in the string S consisting of all the characters(including duplicates) of the string P.  Return "-1" in case there is no such window present. In case there are multiple such windows of same length, return the one with the least starting index.

// Approach:
// At first find the window that satisfies the condition.
// The optimal solution will be a subpart of the window, as the window contains the solution or satisfies the condition.
// Now start trimming the window from the left, as all the subpart of left are already evaluated for the solution.
// Stop where the condition is no more satisfied. Move ahead the j pointer, to a part where the the solution is contained in the window & repeat.

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    string smallestWindow (string given, string search){
        int n = given.size();
        vector<int> fsearch(26, 0);
        for(auto &i: search) fsearch[(i - 'a')] += 1;
        string solution = ""; int length = INT32_MAX;
        
        vector<int> fwindow(26, 0);
        int i=0, j=0;
        while(j < n){
            fwindow[given[j] - 'a'] += 1;
            
            bool check = true;
            for(int i=0; i<26; i++){
                if(fwindow[i] < fsearch[i]){ check = false; break; }    
            }
            
            while(i <= j && check == true){
                if((j-i+1) < length){ solution = given.substr(i, (j-i+1)); length = (j-i+1); }
                fwindow[given[i] - 'a'] -= 1;
                i += 1;
                
                for(int i=0; i<26; i++){
                    if(fwindow[i] < fsearch[i]){ check = false; break; }    
                }
            }
            
            j += 1;
        }
        
        return (solution == "") ? "-1" : solution ;
    }
};

int main(){
    Solution solve;
    
    return 0;
}