#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;


    //constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }

};

// To print Linked List
void print(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << "Data: " << temp->data << endl;
        temp = temp->next;
    }

    cout << endl;
}

// To get the length of the linked list
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

void insertAtHead(Node *&head, Node *&tail, int d)
{
    if (head == NULL)
    { // If there's no starting node
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertAtTail(Node *&tail, Node *&head, int d)
{
    if (tail == NULL)
    {
        Node *temp = new Node(d);
        tail = temp;
        head = temp;
    }

    else
    {
        Node *temp = new Node(d);
        temp->next = NULL;
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insertAtIndex(Node *&head, Node *&tail, int index, int d)
{

    if (index == 0)
    {
        insertAtHead(head, tail, d);
        return;
    }

    Node *temp = head;
    int count = 0;

    while (count < index - 1)
    {
        temp = temp->next;
        count++;
    }

    if (temp->next == NULL)
    {
        insertAtTail(tail, head, d);
        return;
    }

    Node *nodeToOnsert = new Node(d);

    Node *x = new Node(d);
    x->next = temp->next;
    temp->next->prev = x;
    temp->next = x;
    x->prev = temp;
}

int main()
{

    Node *head = NULL;
    Node *tail = NULL;
    print(head);

    insertAtHead(head, tail,  12);
    print(head);

    insertAtTail(tail, head,  15);
    print(head);

    insertAtIndex(head, tail, 2, 20);
    print(head);


    cout<<"Head: "<<head->data<<endl;
    cout<<"Tail: "<<tail->data<<endl;


    getLength(head);

    return 0;
}