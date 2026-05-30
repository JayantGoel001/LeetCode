class Solution {
public:
    vector<int> bt;

    void update(int x, int v) {
        for (; x < bt.size(); x += x & -x) {
            bt[x] = max(bt[x], v);
        }
    }

    int query(int x) {
        int res = 0;
        for (; x > 0; x -= x & -x) {
            res = max(res, bt[x]);
        }
        return res;
    }

    vector<bool> getResults(vector<vector<int>>& queries) {
        int mx = 50000;

        set<int> st = {0, mx};

        for (auto& q : queries) {
            if (q[0] == 1) {
                st.insert(q[1]);
            }
        }

        bt.resize(mx + 1);

        int pre = 0;

        for (int x : st) {
            if (x == 0) {
                continue;
            }
            update(x, x - pre);
            pre = x;
        }

        reverse(queries.begin(), queries.end());
        vector<bool> ans;
        for (auto& q : queries) {
            if (q[0] == 2) {
                int x = q[1];
                int sz = q[2];
                auto it = st.upper_bound(x);
                --it;
                int pre = *it;
                int max_space = query(pre);
                max_space = max(max_space, x - pre);
                ans.push_back(max_space >= sz);
            } else {
                int x = q[1];
                auto it = st.find(x);
                int pre = *prev(it);
                int nxt = *next(it);
                update(nxt, nxt - pre);
                st.erase(it);
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};