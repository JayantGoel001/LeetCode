class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> dp(m, 0);
        int size = 0;
        for(int i=0;i<n;i++) {
            int prev = dp[0];
            for(int j=0;j<m;j++) {
                int temp = dp[j];
                if (i == 0 || j == 0 || matrix[i][j] == '0') {
                    dp[j] = matrix[i][j] - '0';
                } else {
                    dp[j] = 1 + min({dp[j], prev, dp[j - 1]});
                }
                prev = temp;
                size = max(size, dp[j]);
            }
        }

        return size * size;
    }
};