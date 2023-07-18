//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int fun(string &a,string &b,int i,int j,vector<vector<int>>&dp){
            if(i<0 || j<0)return 0;
            if(dp[i][j]!=-1)return dp[i][j];
            if(i==j || a[i]!=b[j])return dp[i][j] = max(fun(a,b,i-1,j,dp),fun(a,b,i,j-1,dp));
            return dp[i][j] = 1+fun(a,b,i-1,j-1,dp);

        }
        int LongestRepeatingSubsequence(string str){
            int n = str.length();
            vector<vector<int>>dp(n,vector<int>(n,-1));
            return fun(str,str,n-1,n-1,dp);
        }

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends