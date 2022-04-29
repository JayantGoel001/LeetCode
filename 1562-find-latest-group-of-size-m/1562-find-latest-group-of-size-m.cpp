class Solution {
public:
    int findLatestStep(vector<int>& A, int m) {
        int res = -1, n = A.size();
        if (n == m) return n;
        vector<int> length(n + 2);
        for (int i = 0; i < n; ++i) {
            int a = A[i], left = length[a - 1], right = length[a + 1];
            length[a - left] = length[a + right] = left + right + 1;
            if (left == m || right == m)
                res = i;
        }
        return res;
    }
};