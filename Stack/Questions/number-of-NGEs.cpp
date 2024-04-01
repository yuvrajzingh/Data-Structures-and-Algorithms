// Number of NGEs to the right
// Given an array of N integers and Q queries of indices, print the number of next greater elements(NGEs) to the right of the given index element. 

#include<bits/stdc++.h>
using namespace std;


// vector<int>count_NGE(int n, int*arr, int queries, int*indices){    Naive Approach
//     vector<int>res;

//     int count;
//     for(int i=0; i<queries; i++){
//         count = 0;
//         for(int j=indices[i]; j<n; j++){
//             if(arr[j] > arr[indices[i]]){
//                 count++;
//             }
//         }
//         res.push_back(count);
//     }
//     return res;
// }

vector<int> count_NGE(int n, int* arr, int queries, int* indices) {
    vector<int> res(n, 0);
    stack<int> st;

    for(int i=n-1; i>=0; i--){
        while(!st.empty() && arr[i] >= arr[st.top()]){
            st.pop();
        }
        res[i] = st.size();
        st.push(i);
    }

    vector<int> result(queries);
    for(int i=0; i<queries; i++){
        result[i] = res[indices[i]];
    }

    return result;
}


int main(){

    int arr[] = {3, 4, 2, 7, 5, 8, 10, 6};
    int queries = 2;
    int indices[] = {0, 5};

    int n = sizeof(arr)/sizeof(arr[0]);

    vector<int>result = count_NGE(n, arr, queries, indices);

    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<" ";
    }

    return 0;
}