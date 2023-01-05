#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // destructor
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

void deleteNode(Node *&head, int index)
{
    // Deleting First Node
    if (index == 0)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }


    // Deleting middle and last node l
    else
    {
        Node *curr = head;
        Node *prev = NULL;

        int count = 0;
        while (count < index)
        {
            prev = curr;
            curr = curr->next;
            count++;
        }

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;

    }


}


// To print the linked List
void print(Node *&head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << "Data: " << temp->data << endl;
        temp = temp->next;
    }

    cout << endl;
}

int main()
{

    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    print(head);

    Node *node2 = new Node(12);
    node1->next = node2;
    print(head);

    Node *node3 = new Node(15);
    node2->next = node3;
    print(head);

    Node *node4 = new Node(17);
    node3->next = node4;
    print(head);

    Node *node5 = new Node(20);
    node4->next = node5;
    node5->next = NULL;
    print(head);

    deleteNode(head, 4);
    print(head);

    return 0;
}