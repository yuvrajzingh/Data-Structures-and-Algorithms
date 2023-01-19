#include<bits/stdc++.h>
using namespace std;

class Node{
    public: 

    int data;
    Node* next;
};

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

int getLength(Node* &head){

    int cnt = 0;
    Node* temp = head;
    while(temp!=NULL){
        temp = temp->next;
        cnt++;
    }

    return cnt;

}

Node* findMiddle(Node* &head){

    int len = getLength(head);
    int ans = (len/2);

    int cnt = 0;

    Node* temp = head;
    while(cnt<ans){
        temp = temp->next;
        cnt++;
    }

    return temp;
}




