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


//Approach 1 
//Time complexity O(n)
//Space complexity O(n)
bool detect(Node* &head){

    if(head==NULL){
        return NULL;
    }

    map<Node* ,bool>visited;

    Node* temp = head;

    while(temp!=NULL){
        if(visited[temp]==true){
            return true;
        }

        visited[temp] = true;

        temp = temp->next;
    }

    return false;
}


//Approach 2 --Floyd Detection Cycle Algorithm--
//Time complexity O(n)
//Space complexity O(1)
Node* floydDetect(Node* &head){
    
    if(head==NULL){
        return NULL;
    }

    Node* slow = head;
    Node* fast  = head;

    while(slow!=NULL && fast!=NULL){
        
        fast = fast->next;
        if(fast!=NULL){
            fast = fast->next;
        }

        slow = slow->next;

        if(slow==fast){
            cout<<"Present at "<<slow->data<<endl;
            return slow;
        }
    }

    return NULL;
}


Node* getStartingNode(Node* &head){
    if(head == NULL){
        return NULL;
    }

    Node* intersection = floydDetect(head);

    if(intersection==NULL){
        return NULL;
    }

    Node* slow = head;

    while(slow!=intersection){
        slow = slow->next;
        intersection = intersection->next;
    }

    return slow;
}

void removeCycle(Node* &head){

    if(head==NULL){
        return;
    }
    Node* startOfCycle = getStartingNode(head);
    if(startOfCycle == NULL){
        return;
    }
    Node* temp = startOfCycle;

    while(temp->next!=startOfCycle){
        temp = temp->next;
    }

    temp->next = NULL;

}

//Utility function
void insertAtTail(Node* &tail, int d){
    Node* temp = new Node(d);
    tail->next = temp;
    tail = tail->next;
}


//traversing
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

    insertAtTail(tail, 20);
    print(head);
    insertAtTail(tail, 30);
    print(head);
    insertAtTail(tail, 40);
    print(head);
    insertAtTail(tail, 50);
    print(head);

    // tail->next = head->next;

    // if(detect(head)){
    //     cout<<"Cycle is present";
    // }
    // else{
    //     cout<<"No cycle present";
    // }
    // cout<<endl;

    // Node* cycle = getStartingNode(head);
    // cout<<"cycle starting at: "<<cycle->data<<endl;
    // removeCycle(head);

    // if(detect(head)){
    //     cout<<"Cycle is present";
    // }
    // else{
    //     cout<<"No cycle present";
    // }

    return 0;
}