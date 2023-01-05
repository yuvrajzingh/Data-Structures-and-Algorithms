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
};
void insertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int d){
    Node* temp = new Node(d);
    tail->next = temp;
    tail = tail->next;
}

void inserAtIndex(Node *&head, Node* &tail, int index, int d)
{

    if (index == 0)
    {
        insertAtHead(head, d);
        return;
    }

    Node *temp = head;
    int count = 0;

    while (count < index - 1)
    {
        temp = temp->next;
        count++;
    }

    if(temp->next == NULL){    //to update tail if the index to be inserted is the last one
        insertAtTail(tail, d);
        return;
    }

    Node *x = new Node(d);
    x->next = temp->next;
    temp->next = x;
}

void print(Node* &head)
{
    Node* temp = head;

    while (temp!= NULL)
    {
        cout << "Data: " << temp->data << endl;
        temp = temp->next;
    }

    cout << endl;
}

int main()
{

    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    print(head);

    insertAtTail(tail, 20);
    print(head);

    insertAtTail(tail, 30);
    print(head);

    inserAtIndex(head, tail, 0, 15);
    print(head);

    return 0;
}