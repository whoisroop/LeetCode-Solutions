// LeetCode - 151. Reverse Words In A String.
// Given an input string s, reverse the order of the words.
// A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.
// Return a string of the words in reverse order concatenated by a single space.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();

        stack<string> stk;
        string word = "";   //Extract words and add it to stack.
        string reverse = "";    //Answer.
        
        for(int i=0; i<n; i++){
            if(s[i]==' '){  //Do not add space into the stack.
                if(word.size()!=0) stk.push(word);  //Check before pushing, if the word contains any letters. Avoid adding space.
                word="";    //Reset Word.
            }
            else word+=s[i];    //Construct Word
        } 
        
        if(word.size()!=0) stk.push(word); //Last Word
        
        while(!stk.empty()){
            reverse += stk.top(); stk.pop(); 
            
            if(stk.size()!=0) reverse += " "; //Except for the last word, add space after every word.
        }
        
        return reverse;
    }
};