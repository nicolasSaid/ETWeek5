#include "DLL.h"

DLL::DLL(){
    head = nullptr;
    tail = nullptr;
}

DLL::DLL(int *x, int size){
    if(size != 0){
        head = new Node(x[0]);
        Node *temp = head;
        tail = head;
        for(int i = 1; i < size/sizeof(int); i++){
            temp->next = new Node(x[i]);
            temp = temp->next;
            tail = temp;
        }
    }
}
ostream& operator<<(ostream& o, DLL x){
    //try to implement this function with a partner!
}

int removeOddNodes(){
    //try to implement this function with a partner!
}

void reverseList(){
    //if we have time, try to implement this function with a partner!
}