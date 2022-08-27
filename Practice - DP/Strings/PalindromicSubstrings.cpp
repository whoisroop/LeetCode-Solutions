//LeetCode - 647 Palindromic Substrings
// Input: s = "aaa"
// Output: 6
// Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
#include<iostream> 
#include<vector>
using namespace std;

class Solution{
private:
    bool isPalindrome(string &s){
        int i=0; int j=s.size()-1;

        if((j+1)==0 || (j+1)==1) return true;   // " " & " A "
        while(i<j){
            if(s[i]==s[j]) {i++; j--;}
            else return false;
        }

        return true;
    }
public:
    int find(int i, int j, string &sa, int size){

    }
};

int main(){

    return 0;
}