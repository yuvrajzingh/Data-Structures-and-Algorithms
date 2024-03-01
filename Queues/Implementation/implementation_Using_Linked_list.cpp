#include<bits/stdc++.h>
using namespace std;

struct QueueNode{
    int data;
    QueueNode* next;

    QueueNode(int d){
        data = d;
        next = nullptr;
    }
};

struct Queue{
    int size;
    QueueNode* front;
    QueueNode* back;

    Queue(){
        front = nullptr;
        back = nullptr;
        size = 0;
    }

    void Enqueue(int x){
        QueueNode* element = new QueueNode(x);
        
        if(size == 0){
            front = element;
            back = element;
        }
        else{
            back->next = element;
            back = element;
        }
        cout<< "Inserted into Queue: "<< x <<endl;
        size++;
    }

    int Dequeque(){

        if(size==0){
            cout<<"Queue is Empty, nothing to dequeue"<<endl;
        }
        else{
            int frontData = front->data;
            QueueNode* temp = front;
            front = front->next;
            delete temp;
            cout<<"Removed from Queue: "<<frontData<<endl;
            size--;
        }
    }

    int Peek(){
        if(front == nullptr){
            return -1;
        }
        else{
            cout<<"The front element of the queue is: "<<front->data<<endl;
        }
    }

    bool Empty(){
        return size == 0;
    }

    int Size(){
        return size;
    }

    void Print(){
        if(size == 0){
            cout<<"Queue Empty ;-;";
        }else{
            QueueNode* temp = front;
            cout<<"Queue elements are: "<<endl;
            while(temp){   
                cout<<"  - "<< temp->data <<endl;
                temp = temp->next;
            }
        }       
    }

};


int main(){

    Queue Q;
    Q.Enqueue(10);
    Q.Enqueue(20);
    Q.Enqueue(30);
    Q.Enqueue(40);
    Q.Dequeque();
    Q.Peek();
    Q.Print();
    Q.Dequeque();
    Q.Dequeque();
    Q.Dequeque();
    Q.Print();
    Q.Empty();


    return 0;
}