#include<bits/stdc++.h>
using namespace std;

class Node{

    public: 

        int data;
        Node* next;
};


void print(Node* &head){

    Node* temp = head;

    while(temp!=head){
        cout<<"Data: "<<temp->data<<endl;
        temp = temp->next;
    }
    cout<<endl;
}

Node* reverse(Node* &head){

    //if the list is single node or empty
    if(head == NULL || head->next == NULL){
        return head;
    }
    
    Node* curr = head;
    Node* prev = NULL;
    Node* forward = NULL;

    while(curr!=NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }

    return prev;

}
