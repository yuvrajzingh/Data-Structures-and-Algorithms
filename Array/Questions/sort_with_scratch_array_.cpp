// Question : Sort an array of size n containing int between 1 and K, given a temp scratch integer array of size K.



#include<bits/stdc++.h>
using namespace std;


void scratchSort(vector<int>&nums, int K){
    
    vector<int>temp(K, 0);
    
    int n = nums.size();

    for(int i=0; i<n; i++){  //
        temp[nums[i]-1]++;
    }

    int j=0;

    for(int i=0; i<K; i++){
        if(temp[i] == 0){
            continue;
        }
        else{
            while(temp[i]--){
                nums[j++] = i+1;
            }
        }
    }
}

int main(){
    
    vector<int> arr = {4, 2, 2, 8, 3, 3, 1};
    int K = 8;

    cout<<"Array before sorting: ";
    for(int i=0; i<arr.size(); i++){
        cout<< arr[i] << " ";
    }

    cout<<endl;

    scratchSort(arr, K);

    cout<<"Array after sorting: ";
    for(int i=0; i<arr.size(); i++){
        cout<< arr[i] << " ";
    }


    return 0;
}
