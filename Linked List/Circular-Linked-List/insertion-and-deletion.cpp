#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "Memory is freed for the node with the data : " << value << endl;
    }

};

void print(Node *&tail)
{
    Node *temp = tail;

    do
    {
        cout << "Data: " << temp->data << endl;
        temp = temp->next;
    } while (temp != tail);

    cout << endl;
}

// In circular linked list there is no point of creating a head as there is no start or end in a CLL
void insertNode(Node *&tail, int element, int d)
{
    // assuming that element is present in the list

    // if list is empty
    if (tail == NULL)
    { 
        Node *temp = new Node(d);
        tail = temp;
        temp->next = temp;
    }

    // if list already has elements
    else
    {
        Node *curr = tail;

        while (curr->data != element)
        {
            curr = curr->next;
        }

        Node *temp = new Node(d);

        temp->next = curr->next;
        curr->next = temp;
    }
}

void deleteNode(Node* &tail, int element){

    //if list is empty
    if(tail == NULL){
        cout<<"List is empty, please insert elements first"<<endl;
        return;
    }

    else{
    //non-empty
    //assuming element is present in the list

        Node* prev = tail;
        Node* curr = prev->next;


        while(curr->data!= element){
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;


        // single node linked list
        if(curr == prev){
            tail = NULL;
        }

        // >= 2 node linked list
        else if(tail == curr){
            tail = prev;
        }

        curr->next = NULL;
        delete curr;    


    }



}


int main()
{

    Node *tail = NULL;

    insertNode(tail, 0, 10);
    print(tail);

    insertNode(tail, 10, 20);
    print(tail);

    insertNode(tail, 20, 40);
    print(tail);

    insertNode(tail, 20, 30);
    print(tail);

    insertNode(tail, 40, 50);
    print(tail);

    deleteNode(tail, 10);
    print(tail);

    return 0;
}