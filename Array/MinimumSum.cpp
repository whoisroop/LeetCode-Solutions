// GFG - Minimum Sum.
// Description - Given an array Arr of size N such that each element is from the range 0 to 9. Find the minimum possible sum of two numbers formed using the elements of the array. All digits in the given array must be used to form the two numbers.

#include<bits/stdc++.h>
using namespace std;

class Solution{   
public:
    string solve(int A[], int n) {
        sort(A, A + n);
        
        string p = "", q = "";
        for(int i=n-1; i>=0; i--){
            if(A[i] == 0) continue;
            if(i%2 == 0) p += to_string(A[i]);
            else q += to_string(A[i]);
        }
        
        // Pad Zero:
        if(p.size() < q.size()) for(int i=0; i<(q.size()-p.size()); i++) p += "0";
        else for(int i=0; i<(p.size()-q.size()); i++) q += "0";
        
        int size = p.size();
        int carry = 0;
        string solution = "";
        for(int i=0; i<size; i++){
            int sum = (p[i] - '0') + (q[i] - '0') + carry;
            carry = sum/10;
            sum = sum % 10;
            solution += to_string(sum);
        }
        
        if(carry != 0){ solution += to_string(carry); }
        
        reverse(solution.begin(), solution.end());
        return solution;
    }
};

int main(){
    Solution solve;
    
    return 0;
}