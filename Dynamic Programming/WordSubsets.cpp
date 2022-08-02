#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<string> wordSubsets(vector<string>& wordsA, vector<string>& wordsB) {
        int nB = wordsB.size();
        vector<string> universal;   //Contains solution.

        vector<int> freq(26, 0);   //To contain net frequency of all words in wordsB.

        for(string &word: wordsB){
            vector<int> temp(26, 0);
            for(char &c: word)  temp[(c - 'a')]++;
            for(int i=0; i<26; i++) if(temp[i]>freq[i]) freq[i] = temp[i];
        }

        for(string &word: wordsA){
            vector<int> temp(26, 0);
            for(char &c: word)  temp[(c - 'a')]++;

            for(int i=0; i<26; i++){
                if((freq[i]!=0) && (temp[i]<freq[i])) break;
                else if(i==25)  universal.push_back(word);
            }

        }
        
        for(string &x: universal) cout << x << " ";
        return universal;
    }
};

int main(){
    vector<string> wordsA = {"amazon","apple","facebook","google","leetcode"};
    vector<string> wordsB = {"e","o"};
    Solution newSol;
    newSol.wordSubsets(wordsA, wordsB);
    return 0;
}