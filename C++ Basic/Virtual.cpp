#include<bits/stdc++.h>
using namespace std;

class A{
public:
    A(){ cout << "A Created!" << endl; }
    virtual ~A(){ cout << "A Deleted!" << endl; }
};

class B: public A{
public:
    B(){ cout << "B Created!" << endl; }
    ~B(){ cout << "B Deleted!" << endl; }
};

int main(){
    B * b = new B();
    A * parent = b;
    cout << "DELETE BEGIN" << endl;
    delete parent;
    cout << "DELETE DONE" << endl;

    return 0;
}