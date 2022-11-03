#include <bits/stdc++.h> 

// Stack class.
class Stack{
public:
    int size;
    int i;
    int *stack;
    
    Stack(int capacity) {
        size = capacity;
        stack = (int *)calloc(size, sizeof(int));
        i = 0;    //Top Element At i-1
    }

    void push(int num) {
        if(i!=size) stack[i++] = num;
    }

    int pop() {    
        if(i!=0){ i--; return stack[i]; }
        else return -1;
    }
    
    int top() {
        if(i!=0) return stack[i-1];
        else return -1;
    }
    
    int isEmpty() {
        if(i==0) return 1;
        else return 0;
    }
    
    int isFull() {
        if(i==size) return 1;
        else return 0;
    }
    
};