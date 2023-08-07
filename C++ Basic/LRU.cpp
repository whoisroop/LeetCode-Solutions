// LeetCode: 
// Description: 
// Approach: 

#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int key;
    int value;
    Node * next;
    Node * previous;
    
    Node(int aK, int aV){
        key = aK;
        value = aV;
        next = NULL;
    }
};

class LRUCache{
private:    
    Node * head; Node * tail;
    int maxsize;
    unordered_map<int, Node *> cache;
    
public:
    // void ihead(); void nremove();
    void ihead(int key, int value){
        Node * node = new Node(key, value);
        
        node->next = head->next;
        node->previous = head;
        
        node->previous->next = node;
        node->next->previous = node;
        
        cache[key] = node;
        return;
    }
    
    void nremove(Node * target){
        target->previous->next = target->next;
        target->next->previous = target->previous;
        
        cache.erase(target->key);
        return;
    }
    
    LRUCache(int C){
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->previous = head;
        
        maxsize = C;
    }
    
    //Function to return value corresponding to the key.
    int GET(int key){
        if(cache.find(key) == cache.end()) return -1;
        
        int value = cache[key]->value;
        nremove(cache[key]);
        ihead(key, value);
        
        return value;
    }
    
    //Function for storing key-value pair.
    void SET(int key, int value){
        if(cache.size() == maxsize && cache.find(key) == cache.end()) nremove(tail->previous);
        
        if(cache.find(key) != cache.end()) nremove(cache[key]);  //If already present:
        ihead(key, value);
        return;
    }
};

int main(){
    
    return 0;
}