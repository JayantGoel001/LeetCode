class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat[0].size();
        vector<int> heights(n, 0);
        int res = 0;
        for (const auto& row : mat) {
            for (int i = 0; i < n; ++i) {
                heights[i] = (row[i] == 0) ? 0 : heights[i] + 1;
            }
            stack<vector<int>> st;
            st.push({-1, 0, -1});
            for (int i = 0; i < n; ++i) {
                int h = heights[i];
                while (st.top()[2] >= h) {
                    st.pop();
                }
                auto& top = st.top();
                int j = top[0];
                int prev = top[1];
                int cur = prev + (i - j) * h;
                st.push({i, cur, h});
                res += cur;
            }
        }
        return res;
    }
};