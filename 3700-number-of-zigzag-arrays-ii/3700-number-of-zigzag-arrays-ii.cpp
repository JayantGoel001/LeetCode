class Solution {
private:
    static constexpr long long MOD = 1'000'000'007;
    using Matrix = vector<vector<long long>>;

    Matrix mul(const Matrix& a, const Matrix& b) {
        int n = a.size();
        int m = b[0].size();
        Matrix res(n, vector<long long>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < a[0].size(); k++) {
                long long r = a[i][k];
                if (r == 0) {
                    continue;
                }
                for (int j = 0; j < m; j++) {
                    res[i][j] = (res[i][j] + r * b[k][j]) % MOD;
                }
            }
        }
        return res;
    }

    Matrix powMul(Matrix base, long long exp, Matrix res) {
        while (exp > 0) {
            if (exp & 1) {
                res = mul(res, base);
            }
            base = mul(base, base);
            exp >>= 1;
        }
        return res;
    }

public:
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        if (n == 1) {
            return m;
        }

        int size = 2 * m;
        Matrix u(size, vector<long long>(size, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < i; j++) {
                u[i][j + m] = 1;
            }
            for (int j = i + 1; j < m; j++) {
                u[i + m][j] = 1;
            }
        }

        Matrix dp(1, vector<long long>(size, 1));

        dp = powMul(std::move(u), n - 1, std::move(dp));

        long long ans = 0;
        for (int i = 0; i < size; i++) {
            ans = (ans + dp[0][i]) % MOD;
        }

        return ans;
    }
};