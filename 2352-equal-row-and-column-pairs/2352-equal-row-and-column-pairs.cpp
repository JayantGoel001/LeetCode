class Solution {
public:
    int equalPairs(vector<vector<int>>& g) {
        int res = 0, n = g.size();
        map<vector<int>, int> m;
        for (int j = 0; j < n; ++j) {
            vector<int> col;
            for (int i = 0; i < n; ++i)
                col.push_back(g[i][j]);
            auto it = m.find(col);
            if (it == end(m))
                m.emplace(move(col), 1);
            else
                ++it->second;
        }
        for (const auto &row : g)
            res += m[row];
        return res;
    }
};