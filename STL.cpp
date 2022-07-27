#include<bits/stdc++.h>
using namespace std;

class STL{
public:
    void vectors(){
        //Vector is internally maintained using singly linked list.
        vector<int> vA = {5,3,9,7};
        vector<int> vB = {1,0,1};

        //Insert into position, from position, till end position.
        vA.insert((vA.begin() + 2), vB.begin(), vB.end());  // vA = {5,3,1,0,1,9,7};

        cout << "INSERT : ";
        for(int i: vA)  cout << i << " ";
        cout << endl;

        //Delete elements from position, till end position.
        vA.erase(vA.begin(), (vA.begin()+3));   // vA = {0,1,9,7};
        vA.back() += 1; // vA = {0,1,9,8};

        cout << "ERASE : "; 
        for(int i: vA)  cout << i << " ";
        cout << endl;
    }

    void lists(){
        //List is internally maintained using doubly linked list. Hence, insertion is faster.
        list<int> li;   //List is similar to vector, in addition it provides front operations.
        li.push_back(1);
        li.push_front(2);

        cout << "Traversal : ";
        for(int &i: li)  cout << i << " ";
        cout << endl;
    }

};

int main(){
    STL containers;
    // containers.lists();
    vector<int> x = {1,5,9};

    return 0;
}