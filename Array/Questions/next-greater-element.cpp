#include<bits/stdc++.h>
using namespace std;


vector<int> nextGreaterEl(vector<int>&nums1, vector<int>&nums2){    //TC:O(n^2)
    vector<int>ans;

    int n1 = nums1.size();
    int n2 = nums2.size();

    for(int i=0; i<n1; i++){
        int j=0;

        while(nums1[i]!=nums2[j]){
            j++;
        }

        while(j<n2 && nums2[j]<=nums1[i]){
            j++;
        }

        if(j==n2){
            ans.push_back(-1);
        } else {
            ans.push_back(nums2[j]);
        }
    }
    return ans;
}

int main(){

    vector<int>nums1 = {4,1,2};
    vector<int>nums2 = {1,3,4,2};

    vector<int>result = nextGreaterEl(nums1, nums2);

    for(int i=0; i<result.size(); i++){
        cout<<result[i] <<" ";
    }

    return 0;
}