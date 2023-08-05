// Problem - 
// Link - 
// Description - 
// Approach - 

#include<bits/stdc++.h>
using namespace std;

// Function & Operator overloading.

// FUNCTION OVERLOADING:

int arithmetic(int a, int b){
    return (a+b);
}

int arithmetic(double a, double b){
    return (a*b);
}

int arithmetic(int a){
    return (a + 1);
}

int arithmetic(double a){
    return (a * 2);
}

// OPERATOR OVERLOADING:
class Z{
private:
    int p;
    int q;
public:
    Z(int ap, int aq){
        p = ap;
        q = aq;
    }

    void print(){
        cout << p << " + " << q << "i" << endl;
    }

    Z operator+(Z const &next){
        Z result(0, 0);

        result.p = p + next.p;
        result.q = q + next.q;

        return result;
    }
};

int main(){
    cout << arithmetic(1, 2) << endl;
    cout << arithmetic(double(2), double(3)) << endl;
    cout << arithmetic(5) << endl;
    cout << arithmetic(double(10)) << endl;


    cout << "OPERATOR OVERLOADING: " << endl;
    Z a(10, 5);
    Z b(2, 4);

    Z c = (a + b);
    a.print(); b.print(); c.print();

    return 0;
}