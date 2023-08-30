#include<bits/stdc++.h>
using namespace std;

void printSub(int idx, vector<int>&ds, int arr[], int n){

    if(idx == n){
        for(auto it: ds){
            cout<< it<< " ";
        }
        if(ds.size() == 0){
            cout<< "{}";
        }
        cout<<endl;
        return ;
    }
    //take the index into subsequence
    ds.push_back(arr[idx]);
    printSub(idx+1, ds, arr, n);
    ds.pop_back();

    //don't take the index into subsequence
    printSub(idx+1, ds, arr, n);

}

int main(){

    int arr[] = {3, 1, 2};
    int n = 3;
    vector<int>ds;
    printSub(0, ds, arr, n);

    return 0;
}