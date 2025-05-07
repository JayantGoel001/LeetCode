#define pii pair<int, int>
#define pip pair<int, pii>
class Solution {
public:
    bool isSafe(int x, int y, int n, int m) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }
    int minTimeToReach(vector<vector<int>>& v) {
        int n = v.size();
        int m = v[0].size();

        queue<pip> q;
        q.push({0, {0, 0}});

        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        dp[0][0] = 0;

        vector<pii> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int mini = INT_MAX;
        while (!q.empty()) {
            pip top = q.front();
            q.pop();

            if (top.second.first == n - 1 && top.second.second == m - 1) {
                mini = min(top.first, mini);
                continue;
            }

            for (auto it : dir) {
                if (isSafe(top.second.first + it.first,
                           top.second.second + it.second, n, m)) {
                    int time =
                        max(top.first, v[top.second.first + it.first]
                                        [top.second.second + it.second]) +
                        1;

                    if (time < dp[top.second.first + it.first]
                                 [top.second.second + it.second]) {
                        dp[top.second.first + it.first]
                          [top.second.second + it.second] = time;

                        q.push({time,
                                {top.second.first + it.first,
                                 top.second.second + it.second}});
                    }
                }
            }
        }

        return mini;
    }
};