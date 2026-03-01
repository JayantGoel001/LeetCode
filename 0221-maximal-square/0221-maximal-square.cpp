class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(2, vector<int> (m, 0));
        int size = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if (i == 0 || j == 0 || matrix[i][j] == '0') dp[i % 2][j] = matrix[i][j] - '0';
                else {
                    dp[i % 2][j] = 1 + min({dp[(i - 1) % 2][j], dp[(i - 1) % 2][j - 1], dp[i % 2][j - 1]});
                }
                size = max(size, dp[i % 2][j]);
            }
        }

        return size * size;
    }
};