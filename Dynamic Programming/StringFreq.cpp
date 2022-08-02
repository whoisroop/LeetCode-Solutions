// A string s is called good if there are no two different characters in s that have the same frequency.

// Given a string s, return the minimum number of characters you need to delete to make s good.

// The frequency of a character in a string is the number of times it appears in the string. For example, in the string "aab", the frequency of 'a' is 2, while the frequency of 'b' is 1.

#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    void mergeSort(int l, int r, vector<int> &array){
        if(l>=r)    return;

        int pivotIndex = r;
        int pivot = array[r];

        int position=-1;
        for(int i=0; i<=pivotIndex; i++){
            if(array[i]>=pivot){
                position++;
                int temp = array[position];
                array[position] = array[i];
                array[i] = temp;
            }
        }

        mergeSort(l, position-1, array);
        mergeSort(position+1, r, array);

        return;
    }

    int makeGood(string word){
        vector<int> freq(26, 0);
        int n = freq.size()-1;

        for(char l: word)   freq[(l - 'a')]++;

        mergeSort(0, freq.size()-1, freq);    //Array Sorted With Freq

        int count = 0;
        for(int i=1; i<freq.size(); i++){
            if(freq[i]==0)  break;

            if(freq[i]>=freq[i-1]){
                int prev = freq[i];
                freq[i] = max(0, (freq[i-1]-1));
                count += (prev - freq[i]);
            }
        }
            return count;

    }

};

int main(){
    string a = "aaabbbccc";

    Solution newSol;
    cout << newSol.makeGood(a);

}