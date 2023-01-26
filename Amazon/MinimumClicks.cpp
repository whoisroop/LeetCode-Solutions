// A recently launched supplemental typing keypad gained significant popularity on amazon shopping due to its flexibility.

// The keypad can be connected to any electronic device and has 9 buttons and each button can have up to 3 lowercase English letters. The buyer has the freedom to choose which letter to place on the button while ensuring that the arrangement is valid. A keypad design is said to be valid if :

// All 26 letters of the English alphabet exist on the keypad.
// Each letter is mapped to exactly one button.
// A button has almost 3 letters mapped to it.

// Given a string text consisting of lower English case letters only find the minimum keypad click count.

// Approach:
// Create a frequency array of the letters in the string.
// First 9 letters will be the first key and will be pressed once for single occurence.
// Next 9 letters in the array will be the second key and will be pressed twice for single occurence.
// Last 8 letters in the array will be the third key and will be pressed thrice for single occurence.

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int keypadCount(string & s){
        int n = s.size();
        vector<int> fmap(26, 0);
        
        for(int i=0; i<n; i++) fmap[(s[i] - 'a')] += 1;

        sort(fmap.begin(), fmap.end(), greater<int> ());

        int click = 0;
        for(int i=0; i<26; i++){
            click += ceil((i+1)/9.0) * fmap[i];
        }

        return click;
    }
};

int main(){
    string sx = "abacadefghibj";
    Solution find;
    cout << find.keypadCount(sx);
    return 0;
}