#include<iostream>
#include<list>
using namespace std;

void showList(list<int> l){
    for(int x: l){
        cout << x << "->";
    }
    cout << "NULL" << endl;
    return;
}

int main(){
    list<int> l = {6,2,4};  //list<int> l(3,0); Same as vector.

    cout << "LIST: " << endl;
    showList(l);

    //Inserting Element Before 6
    list<int>::iterator i = l.begin();
    while((*i)!=6)  i++;    //Find 6 in the list
    l.insert(i, 5);         //Add value using insert

    cout << "Inserted 5: " << endl;
    showList(l);

    advance(i, 2);  //Instead of i++ & i++
    l.insert(i, 3);
    cout << "Inserted 3: " << endl;
    showList(l);

    return 0;
}