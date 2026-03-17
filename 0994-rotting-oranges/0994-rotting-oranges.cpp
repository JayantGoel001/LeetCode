class Solution {
public:
    bool isSafe(vector<vector<int>>& grid, int x, int y, int n, int m) {
        return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>> dir = {
            {0,1},
            {1, 0},
            {-1, 0},
            {0, -1}
        };
        int time = 0;
        queue<vector<int>> q;
        int n = grid.size();
        int m = grid[0].size();

        int rottenOranges = 0;
        int oranges = 0;
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                oranges += grid[i][j] != 0;
                if (grid[i][j] != 2) continue;

                q.push({i, j});
            }
        }

        while(!q.empty()) {
            int size = q.size();
            time++;
            while(size--) {
                vector<int> top = q.front();
                q.pop();
                
                rottenOranges++;
                
                for(auto it : dir) {
                    if (isSafe(grid, top[0] + it[0], top[1] + it[1], n, m)) {
                        q.push({top[0] + it[0], top[1] + it[1]});
                        grid[top[0] + it[0]][top[1] + it[1]] = 2;
                    }
                }
            }
        }
        
        return rottenOranges == oranges ? max(time - 1, 0) : -1;
    }
};