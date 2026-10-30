class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> g(n);
        for (auto& e : edges) {
            g[e[0]].emplace_back(e[1], e[2]);
        }

        vector dis(n, vector<long long>(k + 1, INT_MAX));
        // {shortest path length, node index, number of consecutive identical
        // letters at the end}
        priority_queue<tuple<long long, int, int>,
                       vector<tuple<long long, int, int>>, greater<>>
            pq;

        dis[0][1] = 0;
        pq.emplace(0, 0, 1);

        while (!pq.empty()) {
            auto [d, x, cnt] = pq.top();
            pq.pop();

            if (d > dis[x][cnt]) {
                continue;
            }
            if (x == n - 1) {
                return d;
            }

            for (auto [y, w] : g[x]) {
                int new_cnt = labels[x] == labels[y] ? cnt + 1 : 1;
                if (new_cnt > k) {
                    continue;
                }

                long long nd = d + w;
                if (nd < dis[y][new_cnt]) {
                    dis[y][new_cnt] = nd;
                    pq.emplace(nd, y, new_cnt);
                }
            }
        }

        return -1;
    }
};