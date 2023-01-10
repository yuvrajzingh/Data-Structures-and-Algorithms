#include<bits/stdc++.h>
using namespace std;


class Node{

    public:
    int data;
    Node* next;
    Node* prev;


    //constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }


    //destructor 
    ~Node(){
        int val = this->data;
        if(next!=NULL){
            delete next;
            next = NULL;
        }
        cout<<"Memory free for node with data: "<<val<<endl;
    }
};



void print(Node* &head){
    Node* temp = head;
    
    while(temp!=NULL){
        cout<<"Data: "<<temp->data<<endl;
        temp = temp->next;
    }

    cout<<endl;
}

int getLength(Node *head)
{
    Node *temp = head;
    int len = 0;

    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }

    cout<<"Length of the linked list is: "<<len<<endl;
}

void insertAtTail(Node* &head, Node* &tail, int d){
    if(tail == NULL){
        Node * temp = new Node(d);
        head = temp;
        tail = temp;
    }

    else{
        Node* temp = new Node(d);
        temp->next = NULL;
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}


void deletion(Node* &head, int index){
    if(index == 0){
        Node* temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else{
        Node* curr = head;
        Node* prev = NULL;

        int count = 0;

        while(count<index){
            prev = curr;
            curr = curr->next;
            count++;
        }

        curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}


int main(){

    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    print(head);

    insertAtTail(head, tail, 20);
    print(head);
    insertAtTail(head, tail, 30);
    print(head);
    insertAtTail(head, tail, 40);
    print(head);
    insertAtTail(head, tail, 50);
    print(head);

    cout<<"Head: "<<head->data<<endl;
    cout<<"Tail: "<<tail->data<<endl;

    getLength(head);
    cout<<endl;

    deletion(head, 4);
    print(head);

    cout<<"Head: "<<head->data<<endl;
    cout<<"Tail: "<<tail->data<<endl;

    getLength(head);

    return 0;
}