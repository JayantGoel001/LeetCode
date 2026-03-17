class Solution {
    bool isSafe(int x, int y, int n, int m, vector<vector<char>>& maze) {
        return x >= 0 && x < n && y >= 0 && y < m && maze[x][y] == '.';
    }
    bool canExit(vector<int> &current, vector<int> &entrance, int n, int m) {
        return (current[0] == 0 || current[0] == n - 1 || current[1] == 0 || current[1] == m - 1) && (current[0] != entrance[0] || current[1] != entrance[1]);
    }

public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        vector<vector<int>> dir = {
            {0, 1},
            {1, 0},
            {-1, 0},
            {0, -1}
        };
        int n = maze.size();
        int m = maze[0].size();

        queue<vector<int>> q;
        q.push(entrance);

        int steps = 0;
        while(!q.empty()) {
            int size = q.size();

            while(size--) {
                vector<int> top = q.front();
                q.pop();

                if (canExit(top, entrance, n, m)) {
                    return steps;
                }

                for(auto it : dir) {
                    if (isSafe(top[0] + it[0], top[1] + it[1], n, m, maze)) {
                        q.push({top[0] + it[0], top[1] + it[1]});
                        maze[top[0] + it[0]][top[1] + it[1]] = '+';
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};