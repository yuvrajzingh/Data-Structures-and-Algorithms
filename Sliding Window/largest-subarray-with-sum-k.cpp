//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

//This Solution works only for +ve numbers 


class Solution{
    public:
    int lenOfLongSubarr(int A[],  int n, int k) 
    { 
        // Complete the function
         int i = 0, j = 0, sum = 0;
        int mx = INT_MIN;
        while (j < n) {
            sum += A[j];
            if (sum < k) {
                j++;
            } else if (sum == k) {
                mx = max(mx, j - i + 1);
                j++;
            }
            else if (sum>k){
                while(sum>k){
                    sum = sum - A[i];
                    i++;
                    if(sum==k){
                        mx = max(mx,(j-i+1));
                    }
                }
                j++;
            }
        }
        return mx;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;
    cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends

