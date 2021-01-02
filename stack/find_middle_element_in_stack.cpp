#include<iostream>
using namespace std;

class DoublyLinkedListNode{
    public:
        int data;
        DoublyLinkedListNode * next, *prev, *top, *middle;
        DoublyLinkedListNode(int data = 0, DoublyLinkedListNode * n = NULL, DoublyLinkedListNode * p = NULL){
            this->data = data;
            next = n;
            prev = p;
        }
};


DoublyLinkedListNode * creatNode(int value, DoublyLinkedListNode * n = NULL, DoublyLinkedListNode * p = NULL){
    DoublyLinkedListNode * temp = new DoublyLinkedListNode(value, n, p);
    return temp;
}

void push(DoublyLinkedListNode ** head, DoublyLinkedListNode ** top, int value){
    DoublyLinkedListNode * newNode;
    newNode = creatNode(value);
    if(*head == NULL){
        *head = newNode;
        *top = newNode;

        return;
    }
    else{
        DoublyLinkedListNode *temp = *top;
        temp->next = newNode;
        newNode->prev = temp;
        *top = newNode;
    }
}

void pop(DoublyLinkedListNode ** top){
    DoublyLinkedListNode * temp = *top;
    DoublyLinkedListNode * temp1 = *top;
    temp = temp->prev;
    temp->next = NULL;
    cout<<temp1->data<<endl;
    delete(temp1);
    *top = temp;
}

int topValue(DoublyLinkedListNode ** top){
    DoublyLinkedListNode *node = *top;
    return node->data;
}



int main(){

    return 0;
}