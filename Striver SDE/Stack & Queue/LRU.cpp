// LeetCode - 146. LRU Cache.
// Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

// Implement the LRUCache class:
// LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
// int get(int key) Return the value of the key if the key exists, otherwise return -1.
// void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
// The functions get and put must each run in O(1) average time complexity.

#include<bits/stdc++.h>
using namespace std;

struct NODE{
    int key, value;
    struct NODE * n;
    struct NODE * p;

    NODE(int aKey, int aValue, struct NODE * aP, struct NODE * aN){
        key = aKey;
        value = aValue;
        n = aN;
        p = aP;
    }
};  typedef struct NODE Node;

class LRUCache {
private:
    void insert(Node * cNode, int key, int value){
        Node * newnode = new Node(key, value, cNode, cNode->n);
        newnode->n->p = newnode;
        newnode->p->n = newnode;
    }

    void remove(Node * cNode){
        cNode->p->n = cNode->n;
        cNode->n->p = cNode->p;
    }

public:
    unordered_map<int, Node *> pmap;    //To map key to node that contains the value & order.
    Node * start; Node * end;
    int maxsize; int count;
    
    LRUCache(int capacity) {
        start = new Node(-1, -1, NULL, end);
        end = new Node(-1, -1, start, NULL);
        maxsize = capacity; count = 0;
    }
    
    void put(int key, int value) {
        if(pmap.find(key) != pmap.end()){ remove(pmap[key]); count--; } //If already present remove.

        insert(start, key, value);
        pmap[key] = start->n;
        count++;
        
        if(count > maxsize){
            pmap.erase(pmap.find(end->p->key));
            remove(end->p);
        }
    }

    int get(int key) {
        if(pmap.find(key) == pmap.end()) return -1;

        int value = pmap[key]->value;
        remove(pmap[key]);
        
        insert(start, key, value);   //Node will be inserted after start node.
        pmap[key] = start->n;   //The value is updated not deleted.

        return value;
    }
};