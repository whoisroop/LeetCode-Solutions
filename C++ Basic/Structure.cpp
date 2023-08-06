// LeetCode: 
// Description: 
// Approach: 

#include<bits/stdc++.h>
using namespace std;

struct Student{
public:
    int enroll;
    string name;

    Student(){}
    Student(int aE, string aN){
        enroll = aE;
        name = aN;
    }

    void print(){cout << enroll << " - " << name << endl;}
};

int main(){
    struct Student * a = new Student(1, "Roop"); 
    a->print();
    delete a;

    // Better to use: Above!
    // struct Student * b = (struct Student *) malloc(sizeof(struct Student));
    // b->enroll = 2; b->name = "Sofia";
    // b->print();
    // delete b;

    Student * group = new Student[10];
    group[0].enroll = 2; group[0].name = "Dhvani";
    group[1].enroll = 3; group[1].name = "Sofia";
    group[0].print();
    group[1].print();

    return 0;
}