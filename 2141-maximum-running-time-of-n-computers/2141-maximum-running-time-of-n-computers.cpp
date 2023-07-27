class Solution {
public:
    long long maxRunTime(int n, vector<int>& A) {
        sort(A.begin(), A.end());
        long long sum = accumulate(A.begin(), A.end(), 0L);
        int k = 0, na = A.size();
        while (A[na - 1 - k] > sum / (n - k))
            sum -= A[na - 1 - k++];
        return sum / (n - k);
    }
};