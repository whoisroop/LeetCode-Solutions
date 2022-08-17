//LeetCode - 3. Longest substring with no repeating characters.
#include<iostream>  
#include<vector>
#include<unordered_map>
using namespace std;

class Solution{
public:
    int findLongest(string s){
        int i=0; int j=0;
        int maxi=0;
        int n = s.size();
        unordered_map<char, int> mpp;

        bool isRepeating = false;
        char repeat;
        while(j<n){
            mpp[s[j]]++;
            //At a time we can only have single repeating character & then we start reducing window from left.
            if(mpp[s[j]]>1){ isRepeating = true; repeat = s[j]; }   //Store the repeating character.

            if(isRepeating){
                while(isRepeating){
                    mpp[s[i]]--;    //Reset.
                    if(mpp[repeat]<2) isRepeating = false;  //Check if the repeating character is countered.
                    i++;    //Reducing window
                }

                j++;
            }
            else{
                maxi = max(maxi, (j-i+1));  //The there's no repeating character: Find the length of window.
                j++;
            }
        }

        return maxi;
    }
};

int main(){
    string s = "pwwkew";
    Solution find;
    cout << find.findLongest(s);
    return 0;
}