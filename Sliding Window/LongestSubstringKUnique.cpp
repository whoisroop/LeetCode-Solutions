//LeetCode - Premium : Find longest substring length with k unique characters.
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution{
public:
    int findLength(string &s, int k){
        int i=0; int j=0;
        int n = s.size();
        unordered_map<char, int> mpp;
        int maxi=-1;

        if(n<k) return -1;
        while(j<n){
            mpp[s[j]]++;    //Store character with its frequency.

            if(mpp.size()>k){   //Count of characters is greater.
                while(mpp.size()>k){    //Reduce the window size.
                    mpp[s[i]]--;
                    if(mpp[s[i]]==0) mpp.erase(mpp.find(s[i]));
                    i++; 
                }
                
                j++;
            }
            else if(mpp.size()==k){
                maxi = max(maxi, (j-i+1));
                j++;
            }
            else{
                j++;
            }
        }

        return maxi;
    }
};

int main(){
    string s = "repggxrpnrvy";
    Solution find;
    cout << find.findLength(s, 12);
    return 0;
}