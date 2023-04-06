// GFG - String rp or pr.
// Description - Given a string S. In one operation, you can remove the substring "pr" from the string S and get amount X or you can remove the substring "rp" and get the amount Y. Find the maximum amount you can get if you perform zero or more such operations optimally. 

// Note : 
// Substring of a string S is defined as a continuous sequence of characters in S.
// After removing pr or rp, the order of remaining letters should remain the same.

#include<bits/stdc++.h>
using namespace std;

class Solution{   
public:
    int occurence(string find, string &given){
        int n = given.size();
        char a = find[0];
        char b = find[1];
        
        stack<char> stk;
        int counter = 0;
        for(int i=0; i<n; i++){
            if(given[i] == b && !stk.empty() && stk.top() == a){ counter += 1; stk.pop(); }
            else stk.push(given[i]);
        }
        
        string modified = "";
        while(!stk.empty()){ modified += stk.top(); stk.pop(); }
        reverse(modified.begin(), modified.end());
        given = modified;
        
        return counter;
    }
    
    long long solve(int X, int Y, string S){
        int PR = 0;
        int RP = 0;
        if(X > Y){
            PR = occurence("pr", S);
            RP = occurence("rp", S);
        }
        else{
            RP = occurence("rp", S);
            PR = occurence("pr", S);
        }
        
        return (1LL*PR * X + 1LL*RP * Y);
    }
};

int main(){
    Solution solve;
    
    return 0;
}