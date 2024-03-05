#include<bits/stdc++.h>
using namespace std;

class MinStack{

    stack<pair<int, int>> st;
    int mini = INT_MAX;

    public: 

        void Push(int x){
            if(st.empty()){
                mini = x;
            }else{
                mini = min(x, mini);
            }
            st.push({x, mini});
            cout<<"Element inserted: "<<x<<endl;
        }

        void getMin(){
            if(st.empty()){
                cout<<"The Stack is empty"<<endl;
            }else{
                cout<< "The minimum element in the stack is: "<< st.top().second <<endl;
            }
        }

        void Pop(){
            cout<<"Element popped: "<<st.top().first<<endl;
            st.pop();
        }

        int top(){
            cout<<"The topmost element: "<< st.top().first <<endl;    
        } 


};


int main(){


    MinStack st;
    st.Push(-3);
    st.Push(12);
    st.Push(-4);
    st.Push(6);
    st.top();
    st.Pop();
    st.top();

    st.getMin();

    return 0;
}