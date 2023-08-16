//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the nth catalan number.
    int findCatalan(int n) {
        int MOD = 1e9+7;
        vector<vector<int>>dp(n+1,vector<int>(n+1));
        
        dp[n][n] = 1;
        for(int i=0;i<=n ;i++){
            dp[n][i] = 1;
        }
        
       for(int i=n-1;i>=0;i--){
           for(int j=n-1;j>=0;j--){
               if(i == j){
                   dp[i][j] = dp[i+1][j] % MOD;
               }
               else if(i>j){
                   dp[i][j] = (dp[i+1][j] + dp[i][j+1])%MOD;
               }
           }
       }
       return dp[0][0];
    }
};

//{ Driver Code Starts.
int main() 
{
	int t;
	cin>>t;
	while(t--) {
	    
	    int n;
	    cin>>n;
	    Solution obj;
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}
// } Driver Code Ends