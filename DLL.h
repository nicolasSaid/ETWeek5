#include <stdio.h>
#include <iostream>

using namespace std;

class DLL{
    private:
        class Node{
            public:
                Node* next;
                Node* prev;
                int val;
                Node(){
                    next = nullptr;
                    prev = nullptr;
                    val = -1;
                }
                Node(int val){
                    next = nullptr;
                    prev = nullptr;
                    this->val = val;
                }
        };
        Node *head;
        Node *tail;
    public:
        DLL();
        DLL(int *x, int size);
        friend ostream& operator<<(ostream& o, DLL x);
        int removeOddNodes();
        void reverseList();
};