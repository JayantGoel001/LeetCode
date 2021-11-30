class Solution {
public:    
    int up[210][210], rl[210][210] /*rectangle left*/, rr[210][210] /*rectangle right*/, l[210][210], r[210][210];
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int best = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++)
                if (matrix[i][j] == '1')
                    l[i][j] = j ? (l[i][j - 1] + 1) : 1;
            for (int j = int(matrix[i].size()) - 1; j >= 0; j--)
                if (matrix[i][j] == '1')
                    r[i][j] = j < int(matrix[i].size()) - 1 ? (r[i][j + 1] + 1) : 1;
            for (int j = int(matrix[i].size()) - 1; j >= 0; j--) {
                if (matrix[i][j] == '1') {
                    up[i][j] = i ? 1 + up[i - 1][j] : 1;
                    rl[i][j] = (i && matrix[i - 1][j] == '1') ? min(l[i][j], rl[i - 1][j]) : l[i][j];
                    rr[i][j] = (i && matrix[i - 1][j] == '1') ? min(r[i][j], rr[i - 1][j]) : r[i][j];
                    best = max(best, up[i][j] * (rl[i][j] + rr[i][j] - 1));                    
                }
            }
        }
        return best;
    }
};