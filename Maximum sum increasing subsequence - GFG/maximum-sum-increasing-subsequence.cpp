// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int maxSumIS(int arr[], int n){
	    vector<int> dp(arr,arr + n);
	    
	    for(int i=0;i<n;i++){
	        for(int j=i+1;j<n;j++){
	            if(arr[i] < arr[j] && dp[i] + arr[j] > dp[j]){
	                dp[j] = dp[i] + arr[j];
	            }
	        }
	    }
	    int maxi = INT_MIN;
	    for(auto it : dp){
	        maxi = max(maxi,it);
	    }
	    return maxi;
	}  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends