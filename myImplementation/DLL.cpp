#include "DLL.h"

DLL::DLL(){
    head = nullptr;
    tail = nullptr;
}

DLL::DLL(int *x, int size){
    if(size != 0){
        head = new Node(x[0]);
        Node *temp = head;
        head->next = nullptr;
        tail = head;
        for(int i = 1; i < size/sizeof(int); i++){
            Node *newNode = new Node(x[i]);
            temp->next = newNode;
            newNode->prev = temp;
            temp = temp->next;
            tail = temp;
        }
    }
}
ostream& operator<<(ostream& o, const DLL &x){
    //try to implement this function with a partner!
    DLL::Node *temp = x.head;
    while(temp != nullptr){
        o<<temp->val<<"<->";
        temp = temp->next;
    }
    o<<endl;
    return o;
}

int DLL::removeOddNodes(){
    //try to implement this function with a partner!
    int numNodesRemoved = 0;

    Node *temp = head;
    while(temp!=nullptr){ //go through nodes
        
        if(temp->val % 2 == 1){ //if odd
            if(temp->prev != nullptr){//if we are removing a node not at the head
                temp = temp->prev;
                Node *rem = temp->next;
                temp->next = temp->next->next;
                if(temp->next != nullptr){ //if we are removing a node at the tail
                    temp->next->prev = temp;
                } else {
                    tail = temp;
                }
                delete rem;
                temp = temp->next;
            }else{ //if we are removing a node at the head
                Node *rem = temp;
                temp = temp->next;
                if(temp != nullptr){
                    temp->prev = nullptr;
                    if(temp->next == nullptr){
                        tail = temp;
                    }
                } else {
                    tail = nullptr;
                }
                head = temp;
                delete rem;
            }
            numNodesRemoved++;
        }else{
            temp = temp->next;
        }
    }
    return numNodesRemoved;
}

DLL::~DLL(){
    Node *temp = head;
    Node *del;
    while(temp != nullptr){
        //cout<<temp->val<<endl;
        del = temp;
        cout<<temp<<":";
        temp = temp->next;
        cout<<temp<<endl;
        delete del;
    }
}

void DLL::reverseList(){
    //if we have time, try to implement this function with a partner!
    Node *temp = head;
    head = tail;
    tail = temp;
    while(temp != nullptr){
        Node* next = temp->next;
        temp->next = temp->prev;
        temp->prev = next;
        temp = next;
    }
}