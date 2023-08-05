// LeetCode: 
// Description: 
// Approach: 

#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node * next;

    Node(int aData){
        data = aData;
        next = NULL;
    }
};

class Solution{
private:
public:
    Node * findlongest(Node * head){
        if(head == NULL) return 0;

        Node * ghead = NULL;
        int gsize = 0;

        Node * hnode = head; int count = 1;
        int pvalue = head->data; 

        Node * p = head->next;
        while(p != NULL){
            if(p->data <= pvalue){
                count += 1;
            }
            else{
                if(count > gsize){
                    gsize = count;
                    ghead = head;

                    head = p;
                    count = 1;
                }
            }

            pvalue = p->data;
            p = p->next;
        }

        p = ghead;
        for(int i=0; i<gsize-1; i++) p=p->next;
        p->next = NULL;

        p = ghead;
        while(p!=NULL){ cout << p->data << " "; p = p->next; }
        cout << endl;

        return ghead;
    }
  
};

int main(){
    Solution solve;
    Node * a = new Node(2);
    Node * b = new Node(5);
    Node * c = new Node(4);
    Node * d = new Node(4);
    Node * e = new Node(5);

    a->next=b; b->next=c; c->next=d; d->next=e;
    solve.findlongest(a);
    return 0;
}