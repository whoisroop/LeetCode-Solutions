#include <bits/stdc++.h> 

struct NODE{
    int value;
    struct NODE * next;
    
    NODE(int aValue, struct NODE * aNext){
        value = aValue;
        next = aNext;
    }
};

typedef struct NODE Node;

class Queue {
public:
    Node * start;
    Node * end;
    
    Queue() {
        start = NULL;
        end = NULL;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        if(start == NULL) return 1;
        else return 0;
    }

    void enqueue(int data) {
        if(start == NULL){
            start = new Node(data, NULL);
            end = start;
        }
        else{
            end->next = new Node(data, NULL);
            end = end->next;
        }
    }

    int dequeue() {
        if(start!=NULL){
            int value = start->value;
            start = start->next;
            return value;
        }
        else return -1;
    }

    int front() {
        if(start!=NULL) return start->value;
        else return -1;
    }
};

class QueueArray{
public:
    int * queue;
    int i, j;
    int count, size;
    // Count can be calculated by: (j-i+1)

    QueueArray(int capacity){
        i=0; j=0;
        count=0; 
        size = capacity;

        queue = (int *)calloc(capacity, sizeof(int));
    }

    void enqueue(int value){
        if(count!=size){
            queue[j%size] = value;
            j++; count++;
        }
    }

    int dequeue(){
        if(count!=0){
            i++; count--;
            return queue[(i-1)%size];
        }
        else return -1;
    }

    int top(){
        if(count!=0) return queue[i%size];
        else return -1;
    }
};
