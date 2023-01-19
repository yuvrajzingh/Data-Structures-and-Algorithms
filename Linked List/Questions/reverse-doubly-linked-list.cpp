#include<bits/stdc++.h>
using namespace std;

class Node{

    public:

        int data;
        Node* next;
        Node* prev;


        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};


Node* reverse(Node* &head){
    Node* curr =  head;
    Node* temp = NULL;
    Node* new_head = head;

    if(head == NULL){
        return head;
    }

    while(curr!=NULL){
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        new_head = curr;
        curr = curr->prev;
    }
    return new_head;
}
