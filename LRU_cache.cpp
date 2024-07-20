#include <map>
#include<iostream>

using namespace std;

struct Node{
    int key;
    int val;
    Node* next;
    Node* prev;
};

// Node::Node(int key, int value){
//     this->key= key;
//     this->val= value;
// }

Node* setNode(int key, int value){
    Node* node= new Node();
    node-> val= value;
    node-> key= key;

    return node;
}


class LRU_cache
{
private:
   map<int, Node*> mp;
   int capacity;
   Node* head;
   Node* tail;
   void deleteNode(Node*);
   void insertAtStart(Node*);

public:
    LRU_cache(int, Node* , Node*);
    int get(int);
    void push(int, int);
};

void LRU_cache:: deleteNode(Node* node){
    Node* prevNode= node->prev;
    Node* afterNode= node-> next;

    prevNode-> next= afterNode;
    afterNode-> prev= prevNode;
}

void LRU_cache:: insertAtStart(Node* node){
    Node* curAfterHead= head-> next;
    node-> next= curAfterHead;
    node-> prev= head;
    head-> next= node;
}

LRU_cache::LRU_cache(int cap, Node* head, Node* tail)
{  
    // LRU_cache::capacity= cap;
    this-> capacity= cap;
    this-> mp.clear();  
    this-> head= head;
    this-> tail= tail;
    this-> head-> next= tail;
    this-> tail-> prev= head;
}

int LRU_cache::get(int key){
    if(mp.find(key)== mp.end()) return -1;
    Node* node= mp[key];
    deleteNode(node);
    insertAtStart(node);
    return node-> val;
}

void LRU_cache::push(int key, int value){
    if(mp.find(key)!= mp.end()){
        int _= get(key);
    }else{
        if(mp.size()==capacity){
            Node* node= tail-> prev;
            mp.erase(node-> key);
            deleteNode(node);
        }
        Node* node= setNode(key, value);
        mp[key]= node;
        insertAtStart(node);
    }
}


int main(){

Node* head= setNode(-1, -1);
Node* tail= setNode(-1, -1);

int cap=5;
LRU_cache* lru= new LRU_cache(cap, head, tail);

/*
Here, call the get or push. Please change the capacity of the cache as per your needs. Here I have kept it as 5
*/

return 0;
}









