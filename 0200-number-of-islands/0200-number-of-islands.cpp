#define pii pair<int,int>
class Solution {
public:
    bool isSafe(vector<vector<char>>& grid, int x,int y,int n,int m){
        return x >=0 && x < n && y >= 0 && y < m && grid[x][y] == '1';
    }
    int numIslands(vector<vector<char>>& grid) {
        queue<pii> q;
        int count = 0;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j] == '1'){
                    q.push({i, j});
                    
                    while(!q.empty()){
                        pii top = q.front();
                        q.pop();
                        if(grid[top.first][top.second] == '1'){
                            grid[top.first][top.second] = '0';
                            
                            if(isSafe(grid, top.first - 1, top.second, grid.size(), grid[0].size())){
                                q.push({top.first - 1, top.second});
                            }
                            if(isSafe(grid, top.first, top.second - 1, grid.size(), grid[0].size())){
                                q.push({top.first, top.second - 1});
                            }
                            if(isSafe(grid, top.first + 1, top.second, grid.size(), grid[0].size())){
                                q.push({top.first + 1, top.second});
                            }
                            if(isSafe(grid, top.first, top.second + 1, grid.size(), grid[0].size())){
                                q.push({top.first, top.second + 1});
                            }
                        }
                        
                    }
                    count++;
                }
            }
        }
        
        return count;
    }
};