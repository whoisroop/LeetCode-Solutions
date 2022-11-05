// LeetCode - 460. LFU Cache.

#include<bits/stdc++.h>
using namespace std;

struct NODE{
    int key, value;
    int counter;
    struct NODE * n;
    struct NODE * p;

    NODE(int aKey, int aValue, struct NODE * aP, struct NODE * aN){
        key = aKey;
        value = aValue;
        counter = 1;
        p = aP;
        n = aN;
    }
}; typedef struct NODE Node;

class LFUCache {
private:
    void insert(Node * i, int key, int value){
        if(i==NULL) return;

        Node * newnode = new Node(key, value, i, i->n);
        newnode->p->n = newnode;
        newnode->n->p = newnode;

        count++;
    }

    void remove(Node * i){
        if(i==NULL) return;

        i->p->n = i->n;
        i->n->p = i->p;

        count--;
    }

    void shift(Node * i){
        Node * px = i;
        int countValue = i->counter;
        while(px!=start && countValue == px->p->counter){
            px = px->p;
        }
        if(px == i) return;

        px = px->p;
        //Remove i:
        i->p->n = i->n;
        i->n->p = i->p;

        //Insert i:
        i->p = px;
        i->n = px->n;
        i->p->n = i;
        i->n->p = i;
    }

public:
    unordered_map<int, Node*> pmap;
    Node * start; Node * end;
    int maxsize; int count;

    LFUCache(int capacity) {
        maxsize = capacity; count = 0;
        start = new Node(-1, -1, NULL, NULL);
        end = new Node(-1, -1, NULL, NULL);

        start->n = end;
        end->p = start;
        start->counter = -1; end->counter = -1;
    }
    
    int get(int key) {
        if(pmap.find(key) == pmap.end()) return -1;
        
        pmap[key]->counter += 1;
        shift(pmap[key]);
        return (pmap[key]->value);
    }
    
    void put(int key, int value) {
        if(pmap.find(key)!=pmap.end()){
            pmap[key]->counter += 1;
            pmap[key]->value = value;
            shift(pmap[key]);
        }
        else{
            if(count == maxsize){
                pmap.erase(pmap.find(end->p->key));
                remove(end->p);
            }
            
            insert(end->p, key, value);
            pmap[key] = end->p;
            shift(end->p);
        }
    }
};

int main(){
    LFUCache lfu(2);
    lfu.put(1,1);
    lfu.put(2,4);
    lfu.put(3,9);
    cout << lfu.get(1) << endl;
    cout << lfu.get(2) << endl;

    cout << "ORDER: Most Recent To Least Recent" << endl;
    Node * p = lfu.start;
    while(p!=NULL){
        cout << p->key << " : " << p->value << endl;
        p = p->n;
    }

    return 0;
}