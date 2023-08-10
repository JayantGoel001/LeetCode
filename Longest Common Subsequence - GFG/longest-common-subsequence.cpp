//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    vector<vector<int>> dp;
    //Function to find the length of longest common subsequence in two strings.
    int findLCS(string &str1, string &str2, int x,int y){
        if(x == 0 || y == 0){
            return 0;
        }
        if(dp[x][y] == -1){
            if(str1[x - 1] == str2[y - 1]){
                dp[x][y] = 1 + findLCS(str1, str2, x - 1, y - 1);
            }else{
                dp[x][y] = max(findLCS(str1, str2, x, y - 1), findLCS(str1, str2, x - 1, y));
            }
        }
        return dp[x][y];
    }
    int lcs(int x, int y, string s1, string s2){
        dp.resize(x + 1, vector<int> (y + 1, -1));
        
        return findLCS(s1,s2,x,y);
    }
};



//{ Driver Code Starts.
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends