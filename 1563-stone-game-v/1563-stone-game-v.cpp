class Solution {
private:
    vector<vector<int>> f;
    vector<vector<int>> maxl, maxr;

public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        f.assign(n, vector<int>(n));
        maxl.assign(n, vector<int>(n));
        maxr.assign(n, vector<int>(n));
        for (int left = n - 1; left >= 0; --left) {
            maxl[left][left] = maxr[left][left] = stoneValue[left];
            int sum = stoneValue[left], suml = 0;
            for (int right = left + 1, i = left - 1; right < n; ++right) {
                sum += stoneValue[right];
                while (i + 1 < right && (suml + stoneValue[i + 1]) * 2 <= sum) {
                    suml += stoneValue[i + 1];
                    ++i;
                }
                if (left <= i) {
                    f[left][right] = max(f[left][right], maxl[left][i]);
                }
                if (i + 1 < right) {
                    f[left][right] = max(f[left][right], maxr[i + 2][right]);
                }
                if (suml * 2 == sum) {
                    f[left][right] = max(f[left][right], maxr[i + 1][right]);
                }
                maxl[left][right] =
                    max(maxl[left][right - 1], sum + f[left][right]);
                maxr[left][right] =
                    max(maxr[left + 1][right], sum + f[left][right]);
            }
        }
        return f[0][n - 1];
    }
};