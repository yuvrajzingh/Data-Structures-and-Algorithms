#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *link;

    Node(int data)
    {
        this->data = data;
        this->link = NULL;
    }
};

class Stack
{

    Node *top;

public:
    Stack()
    {
        top = NULL;
    }

    void push(int data)
    {
        Node *temp = new Node(data);

        if (!temp)
        {
            cout << "\nStack Overflow";
            exit(1);
        }
        temp->data = data;
        temp->link = top;
        top = temp;
    }

    bool isEmpty()
    {
        if (top == NULL)
        {
            cout << "\nStack is empty ";
            return 1;
        }
        else
        {
            cout << "\nStack is not empty";
            return 0;
        }
    }

    int peek()
    {
        if (top != NULL)
        {
            cout<<"\nThe top element is : "<<top->data;
            return 1;
        }
        else
        {
            exit(1);
        }
    }

    void pop(){
        Node* temp;

        if(top == NULL){
            cout<<"\nStack Underflow"<<endl;
        }
        else{
            temp = top;

            top = top->link;
            free(temp);
            cout<<"\nElement popped";
        }
    }

    void display(){

        Node* temp;


        if(top == NULL){
            cout<<"\nStack Underflow"<<endl;
            exit(1);
        }
        else{
            temp = top;
            while(temp!=NULL){
                cout<<temp->data;
                temp = temp -> link;

                if(temp){
                    cout<<" -> ";
                } 
            }
        }

    }


};

int main()
{


    Stack st;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    st.display();

    st.peek();
    st.pop();
    st.pop();
    st.pop();
    st.pop();

    st.isEmpty();
    


    return 0;
}