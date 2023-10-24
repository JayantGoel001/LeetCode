//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int palindromicPartition(string str){
        int n = str.size();
        vector<vector<bool>> dp(n,vector<bool> (n,false));
        vector<int> minCut(n,0);
        for(int i=0;i<n;i++){
            minCut[i] = i;
            for(int j=0;j<=i;j++){
                if(str[i] == str[j] && (i - j < 2 || dp[j+1][i-1])){
                    dp[j][i] = true;
                    minCut[i] = min(minCut[i],j == 0 ? 0 : (minCut[j - 1] + 1));
                }
            }
        }
        return minCut[n-1];
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends