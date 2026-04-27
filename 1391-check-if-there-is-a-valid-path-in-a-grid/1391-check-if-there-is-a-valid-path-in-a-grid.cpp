class Solution {
public:
    static constexpr int MAX_N = 300 * 300 + 5;
    static constexpr int patterns[7] = {0,      0b1010, 0b0101, 0b1100,
                                        0b0110, 0b1001, 0b0011};
    static constexpr int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    struct DisjointSet {
        int f[MAX_N];

        DisjointSet() {
            for (int i = 0; i < MAX_N; ++i) f[i] = i;
        }

        int find(int x) { return x == f[x] ? x : f[x] = find(f[x]); }

        void merge(int x, int y) { f[find(x)] = find(y); }
    } ds;

    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        auto getId = [&](int x, int y) { return x * n + y; };

        auto handler = [&](int x, int y) {
            int pattern = patterns[grid[x][y]];
            for (int i = 0; i < 4; ++i) {
                if (pattern & (1 << i)) {
                    int sx = x + dirs[i][0];
                    int sy = y + dirs[i][1];
                    if (sx >= 0 && sx < m && sy >= 0 && sy < n and
                        (patterns[grid[sx][sy]] & (1 << ((i + 2) % 4)))) {
                        ds.merge(getId(x, y), getId(sx, sy));
                    }
                }
            }
        };

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                handler(i, j);
            }
        }

        return ds.find(getId(0, 0)) == ds.find(getId(m - 1, n - 1));
    }
};