#include<bits/stdc++.h>
using namespace std;


class Node{

    public:

        int data;
        Node* next;


        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

Node* reverse(Node* &head, int k){

    if(head == NULL){
        return NULL;
    }

    Node* curr = head;
    Node* forward = NULL;
    Node* prev = NULL;
    
    int count = 0;
    while(curr!=NULL && count < k){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }

    if(forward != NULL){
        head->next = reverse(forward, k);
    }

}
