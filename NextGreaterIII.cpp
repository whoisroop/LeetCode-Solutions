#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findNextSmaller(int n){
        vector<int> digit;

        if(n<10)    return -1;

        while(n){
            digit.push_back(n%10);
            n=n/10;
        }

        reverse(digit.begin(), digit.end());

        //Digit Vector contains all the digits of the number.

        for(auto i: digit){
            cout << i << " ";
        }
        cout << endl;

        int length = digit.size();
        int indexA = -1;
        int indexB = -1;

        //Direction <-- From Unit Digit To Left.
        for(int i=length-1; i>0; i--){
            //Find the first decreasing digit from unit digit. 1 (5) 6 4 2
            if(digit[i-1]<digit[i]){  
                indexA = i-1;
                break;
            }
            else if(i==1)   return -1;
        }

        for(int i=length-1; i>indexA; i--){ 
            //First greater element from unit digit. 1 5 (6) 4 2
            if(digit[i]>digit[indexA]){
                indexB = i;
                break;
            }
        }
        cout << "IndexA : " << indexA << " | IndexB : " << indexB << endl;

        // SWAP indexA & indexB. 1 (5) (6) 4 2
        digit[indexA] = digit[indexA] + digit[indexB];
        digit[indexB] = digit[indexA] - digit[indexB];
        digit[indexA] = digit[indexA] - digit[indexB];

        for(auto i: digit)  cout << i << " ";
        cout << endl;

        reverse(digit.begin()+(indexA+1), digit.end());   // 1 6 | 5 4 2 --> 1 6 2 4 5
        
        int answer=0;

        for(int i=0; i<length; i++){
            if(answer > (INT32_MAX - digit[i])/10)   return -1;
            answer = 10*answer + digit[i];
        }

        return answer;
    }
};

int main(){
    int x = 2147483476;
    Solution newSol;
    cout << newSol.findNextSmaller(x);
    return 0;
}