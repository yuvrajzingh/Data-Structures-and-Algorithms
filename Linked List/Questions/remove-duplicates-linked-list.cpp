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


void UnsortedDuplicates(Node* head){
    if(head==NULL){
        return ;
    }

    map<Node*, bool> visited;

    Node* curr = head;

    while(curr->next != NULL){
        visited[curr] = true;

        if(visited[curr->next] == true){
            Node* dup = curr->next;
            curr->next = curr->next->next;
            delete(dup);
        }

        else{
            curr = curr->next;
        }
    }
} 

void remove_duplicates(Node* head) {
    Node *ptr1, *ptr2, *dup;
    ptr1 = head;

    while (ptr1 != NULL && ptr1->next != NULL) {
        ptr2 = ptr1;
 
        while (ptr2->next != NULL) {

            if (ptr1->data == ptr2->next->data) {
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                delete (dup);
            } else 
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}


//utility function
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

    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    
    print(head);
    
    pushNode(tail, 30);
    print(head);
    pushNode(tail, 50);
    print(head);
    pushNode(tail, 30);
    print(head);
    pushNode(tail, 40);
    print(head);
    pushNode(tail, 60);
    print(head);

    // remove_duplicates(head);
    UnsortedDuplicates(head);
    print(head);

  return 0;
}