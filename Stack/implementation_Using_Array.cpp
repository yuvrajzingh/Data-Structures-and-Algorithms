#include<bits/stdc++.h>
using namespace std;


class Stack{
    
    //properties
    public:

        int *arr;
        int top;
        int size;

    //behaviour

    Stack(int size){
        this -> size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element){
        if(size - top > 1){
            top++;
            arr[top] = element;
        }
        else{
            cout<<"Stack Overflow";
        }
    }

    void pop(){
        if(top>=0){
            top--;
        }
        else{
            cout<<"Stack Underflow";
        }
    }

    int peek(){
        if(top>=0){
            return arr[top];
        }
        else{
            cout<<"The stack is empty";
            return -1;
        }
    }

    bool isEmpty(){
        if(top==-1){
            cout<<"Stack is empty ";
            return 1;
        }
        else{
            cout<<"Stack is not empty";
            return 0;
        }
    }


};

int main(){


    Stack st(5);

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);


    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek()<<endl;
    st.pop();
    
    st.isEmpty();



    return 0;
}