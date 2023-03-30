class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (n, vector<int> (n)));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dp[1][i][j] = s1[i] == s2[j];
            }
        }
        
        for(int len=2;len<=n;len++){
            for(int i=0;i<n+1-len;i++){
                for(int j=0;j<n+1-len;j++){
                    for(int l=1;l<len;l++){
                        dp[len][i][j] |= dp[l][i][j] && dp[len - l][i + l][j + l];
                        dp[len][i][j] |= dp[l][i][j + len - l] && dp[len - l][i + l][j];
                    }
                }
            }
        }
        return dp[n][0][0];
    }
};