class State {
public:
    int x;
    int y;
    int dis;
    State(int x, int y, int dis) : x(x), y(y), dis(dis) {}
};
class Solution {
public:
    const int inf = 0x3f3f3f3f;
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<int>> d(n, vector<int>(m, inf));
        vector<vector<int>> v(n, vector<int>(m, 0));

        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        d[0][0] = 0;

        auto cmp = [](const State& a, const State& b) { return a.dis > b.dis; };
        priority_queue<State, vector<State>, decltype(cmp)> q(cmp);
        q.push(State(0, 0, 0));

        while (q.size()) {
            State s = q.top();
            q.pop();
            if (v[s.x][s.y]) {
                continue;
            }
            if (s.x == n - 1 && s.y == m - 1) {
                break;
            }
            v[s.x][s.y] = 1;
            for (int i = 0; i < 4; i++) {
                int nx = s.x + dirs[i][0];
                int ny = s.y + dirs[i][1];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                    continue;
                }
                int dist =
                    max(d[s.x][s.y], moveTime[nx][ny]) + (s.x + s.y) % 2 + 1;
                if (d[nx][ny] > dist) {
                    d[nx][ny] = dist;
                    q.push(State(nx, ny, dist));
                }
            }
        }
        return d[n - 1][m - 1];
    }
};