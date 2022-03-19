#define ll long long int
class Solution {
public:
    vector<vector<ll>> dp;
    ll count(string &a, string &b, int m, int n){
        if ((m == 0 && n == 0) || n == 0)
            return (ll)1;

        if (m == 0)
            return (ll)0;
        
        if(dp[m][n] != -1){
            return dp[m][n];
        }
        if (a[m - 1] == b[n - 1])
            dp[m][n] = count(a, b, m - 1, n - 1) +  count(a, b, m - 1, n);
        else
            dp[m][n] = count(a, b, m - 1, n);
        return dp[m][n];
    }

    long long maximumSubsequenceCount(string text, string pattern) {
        dp.resize(text.size() + 2,vector<ll>(pattern.size() + 1, -1));
        
        string X = pattern[0] + text;
        ll count1 = count(X,pattern,text.size()+1,2);
        
        dp.assign(text.size() + 2,vector<ll>(pattern.size() + 1, -1));
        X = text + pattern[1];
        ll count2 = count(X,pattern,text.size()+1,2);
        return max(count1, count2);
    }
};