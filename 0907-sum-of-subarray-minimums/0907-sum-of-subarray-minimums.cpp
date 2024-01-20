class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const int mod = 1e9 + 7;
        int N = arr.size();
        stack<int> st;
        vector<int> right(N), sum(N + 1);

        for (int i = 0; i < N; ++i) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                int a = st.top();
                st.pop();
                right[a] = i;
            }
            st.push(i);
        }

        while (!st.empty()) {
            int a = st.top();
            right[a] = N;
            st.pop();
        }

        for (int i = N - 1; i >= 0; --i) {
            sum[i] = ((arr[i] * 1ll * (right[i] - i)) % mod + sum[right[i]]) % mod;
        }

        int cnt = 0;
        for (int i = 0; i < N; ++i) {
            cnt = (cnt + sum[i]) % mod;
        }

        return cnt;
    }
};