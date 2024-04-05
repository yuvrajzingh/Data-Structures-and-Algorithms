//We are given an array asteroids of integers representing asteroids in a row.
// For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.
// Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.


#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        int n = asteroids.size();

        for(int i=0; i<n; i++){
            if(st.empty() || asteroids[i] > 0){
            st.push(asteroids[i]);
            }
            else {
                while(!st.empty() && st.top() > 0 && st.top() < -asteroids[i]){
                    st.pop();
                }
                if(st.empty() || st.top() < 0){
                    st.push(asteroids[i]);
                }
                else if(st.top() == -asteroids[i]){
                    st.pop();
                }
            }
        }

        vector<int>res(st.size());

        for(int i=st.size()-1; i>=0; i--){
            res[i] = st.top();
            st.pop();
        }
       
        return res;

    }
};

int main(){
    Solution asteroid;

    vector<int> asteroids({5,10,-5});

    vector<int>ans = asteroid.asteroidCollision(asteroids);

    cout<<"The asteroid left are : "<<endl;

    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<endl;
    }

    return 0;
}