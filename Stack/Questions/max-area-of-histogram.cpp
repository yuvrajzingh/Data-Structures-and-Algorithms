// Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

#include<bits/stdc++.h>
using namespace std;


class Solution {

private: 
    vector<int> NSEL(vector<int>& heights){
        int n = heights.size();
        vector<int> nsel(n, -1);
        stack<pair<int, int>> st;

        for(int i=0; i<n; i++){
            while(!st.empty() && st.top().first >= heights[i]){
                st.pop();
            }
            if(!st.empty()){
                nsel[i] = st.top().second;
            }
            st.push({heights[i], i});
        }
        return nsel;
    }

    vector<int> NSER(vector<int>& heights){
        int n = heights.size();
        vector<int> nser(n, n);
        stack<pair<int, int>> st;

        for(int i=n-1; i>=0; i--){
            while(!st.empty() && st.top().first >= heights[i]){
                st.pop();
            }
            if(!st.empty()){
                nser[i] = st.top().second;
            }
            st.push({heights[i], i});
        }
        return nser;
    }

public:
    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();

        vector<int> left = NSEL(heights);
        vector<int> right = NSER(heights);

        int max_area = 0;
        for(int i=0; i<n; i++){
            int width = right[i] - left[i] - 1;
            int area = width * heights[i];
            max_area = max(max_area, area);
        }

        return max_area;
    
    }
};



int main(){
    Solution MAH;

    vector<int> heights({2,1,5,6,2,3});

    int maxArea = MAH.largestRectangleArea(heights);

    cout<<"The max area of this histogram is -> "<<maxArea;

    return 0;
}