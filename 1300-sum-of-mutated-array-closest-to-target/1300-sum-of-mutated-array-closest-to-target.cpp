class Solution {
public:
    int findBestValue(vector<int>& A, int target) {
        sort(A.begin(), A.end());
        int n = A.size(), i = 0;
        while (i < n && target > A[i] * (n - i)){
            target -= A[i++];
        }
        return i == n ? A[n - 1] : int(round((target - 0.0001) / (n - i)));
    }
};