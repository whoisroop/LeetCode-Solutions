// LeetCode - 146. LRU Cache.
// Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

// Implement the LRUCache class:
// LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
// int get(int key) Return the value of the key if the key exists, otherwise return -1.
// void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
// The functions get and put must each run in O(1) average time complexity.

// Approach:
// The idea is to remove the last operated value when the size of cache is full & maintain the relative order of the keys.
// Operated? Put or Get - Whenever either of them are called for a key. It becomes the most recently used.
// Use a linked list to store the corresponding order of the keys from start to end (Most Recent ... Least Recent).
// Use a map to map the key to its corresponding node that stores the value to the key, as well as the order.
// Why doubly linked list : The order of the node can be easily manipulated. O(1) : Insertion & Deletion.
// When the cache (list) is full remove the element from end & also its key from the map.

#include<bits/stdc++.h>
using namespace std;

// Doubly Linked List Node.
struct NODE{
    int key, value;
    struct NODE * n;
    struct NODE * p;

    NODE(int aKey, int aValue, struct NODE * aP, struct NODE * aN){
        key = aKey;
        value = aValue;
        p = aP;
        n = aN;
    }
};  typedef struct NODE Node;

class LRUCache {
    //Insert after a node & delete a node:
private:
    void insert(Node * cNode, int key, int value){
        Node * newnode = new Node(key, value, cNode, cNode->n);
        newnode->n->p = newnode;
        newnode->p->n = newnode;

        count++;
    }

    void remove(Node * cNode){
        cNode->p->n = cNode->n;
        cNode->n->p = cNode->p;

        count--;
    }

public:
    unordered_map<int, Node *> pmap;    //To map key to node that contains the value & order.
    Node * start; Node * end;
    int maxsize; int count;
    
    LRUCache(int capacity) {
        start = new Node(-1, -1, NULL, NULL);
        end = new Node(-1, -1, NULL, NULL);
        maxsize = capacity; count = 0;
        
        //During the time of initialization both are not intitialized.
        start->n = end; 
        end->p = start;
    }
    
    void put(int key, int value) {
        if(pmap.find(key) != pmap.end()){ remove(pmap[key]); } //If already present remove.

        insert(start, key, value);
        pmap[key] = start->n;
        
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

int main(){
    LRUCache lru(2);
    lru.put(1,1);
    lru.put(2,4);
    lru.put(3,9);

    cout << "ORDER: Most Recent To Least Recent" << endl;
    Node * p = lru.start;
    while(p!=NULL){
        cout << p->key << " : " << p->value << endl;
        p = p->n;
    }

    return 0;
}