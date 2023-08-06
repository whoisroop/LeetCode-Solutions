// LeetCode: 
// Description: 
// Approach: 

// SHALLOW VS DEEP COPY

#include<bits/stdc++.h>
using namespace std;

class SomeClass{
public:
    int value;
    int * key;
    
    SomeClass(){}
    SomeClass(int aValue, int aKey){
        value = aValue;
        key = new int(aKey);
    }

    void DEEP(SomeClass &Y){
        value = Y.value;
        key = new int(*(Y.key));
        return;
    }
};

int main(){
    // Shallow Copy: Copies the value & the pointer right away.
    SomeClass X(6, 36);
    SomeClass Y = X;
    cout << "SHALLOW COPY: " << endl;
    cout << *(X.key) << " & " << *(Y.key) << endl;

    // ISSUE:
    *(X.key) = 69;
    cout << *(X.key) << " & " << *(Y.key) << endl;

    // Create a deep copy function:
    SomeClass A(3, 9);
    SomeClass B;
    B.DEEP(A);

    cout << "\nDEEP COPY: " << endl;
    cout << *(A.key) << " & " << *(B.key) << endl;
    *(A.key) = 69;
    cout << *(A.key) << " & " << *(B.key) << endl;
    
    return 0;
}