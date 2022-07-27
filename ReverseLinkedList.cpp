#include<iostream>
#include<math.h>
using namespace std;

class Node{
    public:
    int value;
    Node * next;

    public:
    Node(int aValue){
        value = aValue;
        next = NULL;
    }
};

class Solution {
public:

    Node * reverseLinkedList(Node * curr, Node * prev = NULL){
        if(curr == NULL){
            Node * newHead = prev;
            return newHead;
        }

        Node * newHead = reverseLinkedList(curr->next, curr);

        curr->next = prev;
        return newHead;
    }

    Node * middleOfLL(Node * head){     //Node -> Next = MIDDLE & Value = Elements
        Node * s = head;
        Node * f = head;
        int count = 1;

        while(f->next!=NULL && f->next->next!=NULL){
            s = s->next;
            f = f->next->next;
            count++;
        }

        if(f->next->next==NULL) count = 2*count;    //Even
        else    count = (2*count - 1);

        Node * LL = new Node(count);
        LL->next = s;

        return LL; 
    }
    
};

void display(Node * head){
    cout << "\nLinked List:" << endl;
    while(head!=NULL){
        cout << head->value << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main(){
    Node A(1);
    Node B(2);
    Node C(3);
    Node D(4);

    Node * head = &A;
    A.next = &B;
    B.next = &C;
    C.next = &D;
    
    display(head);
    Solution x;

    Node * middle = x.middleOfLL(head);
    cout << "Middle element: " << middle->next->value << endl;
    cout << "Number Of Elements: " << middle->value << endl;

    return 0;
}