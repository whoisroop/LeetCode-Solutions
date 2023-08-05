// Problem - 
// Link - 
// Description - 
// Approach - 

#include<bits/stdc++.h>
using namespace std;

class Human{
public:
    Human(){}

    void age(){
        cout << "0-99" << endl;
    }

    virtual void vage(){
        cout << "0-99" << endl;
    }
};

class Adult : public Human{
public:
    Adult(){}

    void age(){
        cout << "18-99" << endl;
    }

    void vage() override{
        cout << "18-99" << endl;
    }
};

int main(){
    Human * human = new Human();
    Adult * adult = new Adult();

    // As the adult is also a human, the following is also valid:
    Human * x = adult;

    cout << "WITHOUT VIRTUAL FUNCTION: " << endl;
    human->age();   //0-99
    x->age();   //0-99
    // USE VIRTUAL FUNCTION, the functions which can be overwritten (overriden) in the derived class. 
    cout << "WITH VIRTUAL FUNCTION: " << endl;
    human->vage();
    x->vage();
    return 0;
}