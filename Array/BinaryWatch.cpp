//LeetCode - 401. Binary Watch.
//A binary watch has 4 LEDs on the top to represent the hours (0-11), and 6 LEDs on the bottom to represent the minutes (0-59). Each LED represents a zero or one, with the least significant bit on the right.
//Given an integer turnedOn which represents the number of LEDs that are currently on (ignoring the PM), return all possible times the watch could represent. You may return the answer in any order.

#include<iostream>
#include<vector>
#include<bitset>
using namespace std;

class Solution{
public:
    vector<string> findTimes(int onLED){
        vector<string> time;
        for(int h=0; h<12; h++){
            for(int m=0; m<60; m++){
                int set = __builtin_popcount(h) + __builtin_popcount(m);
                if(set == onLED){
                    time.push_back(to_string(h) + ((m<10) ? "0:" : ":") + to_string(m));
                }
            }
        }

        return time;
    }
};

int main(){
    bitset<8> bset(25);
    
    return 0;
}