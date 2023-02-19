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

void sortList(Node * &head)
{
    int zeroCnt = 0;
    int oneCnt = 1;
    int twoCnt = 2;

    Node* temp = head;

    while(temp!=NULL){
        if(temp->data==0){
            zeroCnt++;
        }
        else if(temp->data==1){
            oneCnt++;
        }
        else if(temp->data==2){
            twoCnt++;
        }
        temp = temp->next;

    }

    temp = head;

    while(temp!=NULL){
        if(zeroCnt!=0){
            temp->data = 0;
            zeroCnt--;
        }
        else if(oneCnt!=1){
            temp->data = 1;
            oneCnt--;
        }
        else if(twoCnt!=2){
            temp->data = 2;
            twoCnt--;
        }

        temp = temp->next;
    }

}

// utility function
void pushNode(Node* &tail, int data){
    Node* temp = new Node(data);
    tail->next = temp;
    tail = tail->next;
}

//Traversal 
void print(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<"Data: "<<temp->data<<endl;
        temp = temp->next;
    }
    cout<<endl;
}

int main(){

    Node* node1 = new Node(1);
    Node* head = node1;
    Node* tail = node1;
    print(head);

    pushNode(tail, 0);
    print(head);

    pushNode(tail, 2);
    print(head);
 
    pushNode(tail, 1);
    print(head);

    pushNode(tail, 2);
    print(head);

    pushNode(tail, 2);
    print(head);

    pushNode(tail, 0);
    print(head);

    cout<<"After sorting the list: "<<endl;

    sortList(head);
    print(head);

    return 0;
}