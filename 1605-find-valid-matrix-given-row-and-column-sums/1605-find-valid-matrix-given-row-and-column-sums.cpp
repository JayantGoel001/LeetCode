class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum,
                                      vector<int>& colSum) {
        int N = rowSum.size();
        int M = colSum.size();

        vector<vector<int>> origMatrix(N, vector<int>(M, 0));
        int i = 0, j = 0;

        while (i < N && j < M) {
            origMatrix[i][j] = min(rowSum[i], colSum[j]);

            rowSum[i] -= origMatrix[i][j];
            colSum[j] -= origMatrix[i][j];

            rowSum[i] == 0 ? i++ : j++;
        }
        return origMatrix;
    }
};