#include<bits/stdc++.h>
using namespace std;

class Node{
    public:

    int data;
    Node* next;

};

void circular(Node* &head)
{
    if(head == NULL){
       cout<<"Linked List is circular in nature" ; 
    }

    Node* temp = head->next;

    while(temp!=NULL && temp!=head){
        temp = temp -> next;
    }

    if(temp == head){
        cout<<"Linked List is circular in nature";
    }

    cout<<"Linked List is not circular";


}


//Time complexity O(n)
//Space complexity O(1) 