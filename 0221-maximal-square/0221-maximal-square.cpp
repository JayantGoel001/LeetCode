class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int> (m, 0));
        int size = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if (i == 0 || j == 0 || matrix[i][j] == '0') dp[i][j] = matrix[i][j] - '0';
                else {
                    dp[i][j] = 1 + min({dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]});
                }
                size = max(size, dp[i][j]);
            }
        }

        return size * size;
    }
};