#include<bits/stdc++.h>
using namespace std;


//* these two approach is used for a linear array.

// vector<int> nextGreaterEl(vector<int>&nums){    //TC:O(n^2)
    
//     int n = nums.size();
//     vector<int>ans(n, -1);

   

//     for(int i=0; i<n; ++i){
//         for(int j=1; j<n; ++j){
//             int nextIdx = (i+j)%n;

//             if(nums[nextIdx] > nums[i]){
//                 ans[i] = nums[nextIdx];
//                 break;
//             }

//         }
//     }
//     return ans;
// }


// vector<int> nextGreaterEl(vector<int>&nums){   //TC:O(n) SC:O(n)
    
//     int n = nums.size();
//     vector<int>ans(n);
//     stack<int>st;
   

//     for(int i=n-1; i>=0; i--){
        
//         if(st.empty()){
//             st.push(nums[i]);
//             ans[i] = -1;
//         }else if(nums[i] < st.top()){
//             ans[i] = st.top();
//             st.push(nums[i]);
//         }else{
//             while(!st.empty() && st.top() <= nums[i]){
//                 st.pop();
//             }
//             ans[i] = st.empty() ? -1 : st.top();
//             st.push(nums[i]);
//         }
//     }
//     return ans;
// }


//* This approach is used when we are trying to find NGE in a circular array 

vector<int> nextGreaterEl(vector<int>&nums){   //TC:O(n) SC:O(n)
    
    int n = nums.size();
    vector<int>ans(n, -1);
    stack<int>st;
   

    for(int i=2*n-1; i>=0; i--){
        
        while(!st.empty() && st.top() <= nums[i%n]){
            st.pop();
        }

        if(i<n){
            if(!st.empty()){
                ans[i] = st.top();
            }    
        }
        st.push(nums[i%n]);
    }
    return ans;
}



int main(){

    vector<int>nums = {5,7,1,7,6,0};


    vector<int>result = nextGreaterEl(nums);

    for(int i=0; i<result.size(); i++){
        cout<<result[i] <<" ";
    }

    return 0;
}