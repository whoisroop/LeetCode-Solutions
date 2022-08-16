//LeetCode - 187. Given a string s that represents a DNA sequence, return all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule. You may return the answer in any order.
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution{
public:
    vector<string> findRepeated(string dna){
        int i=0; int j=0;
        int window = 10;
        unordered_map<string, int> mpp;
        vector<string> sol;

        int l = dna.size();
        string sequence = "";
        while(j<l){ //O(N): Length Of DNA
            if((j-i+1)<window){
                sequence += dna[j];

                j++;
            }
            else{
                sequence += dna[j];

                mpp[sequence]++;
                sequence.erase(sequence.begin());   //O(10)

                i++; j++;
            }
        }

        for(auto &i: mpp) if(i.second > 1)  sol.push_back(i.first);
        for(string &i: sol)  cout << i << " ";
        return sol;
    }
};

int main(){
    string dna = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    Solution find;
    find.findRepeated(dna);
    return 0;
}