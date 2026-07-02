class Solution {
    static constexpr int DIRS[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dis(m, vector<int>(n, INT_MAX));

        deque<pair<int, int>> q;
        q.emplace_front(0, 0);
        dis[0][0] = grid[0][0];

        while (!q.empty()) {
            auto [cx, cy] = q.front();
            q.pop_front();
            // the first time it leaves the queue, the shortest distance is
            // guaranteed
            if (cx == m - 1 && cy == n - 1) {
                return true;
            }

            for (auto& [dx, dy] : DIRS) {
                int nx = cx + dx, ny = cy + dy;
                if (nx < 0 || ny < 0 || nx >= m || ny >= n) {
                    continue;
                }
                int cost = dis[cx][cy] + grid[nx][ny];
                // pruning: the new distance does not meet health requirements
                if (cost >= health) {
                    continue;
                }
                if (cost < dis[nx][ny]) {
                    dis[nx][ny] = cost;
                    if (grid[nx][ny] == 0) {
                        q.emplace_front(nx, ny);
                    } else {
                        q.emplace_back(nx, ny);
                    }
                }
            }
        }

        return false;
    }
};