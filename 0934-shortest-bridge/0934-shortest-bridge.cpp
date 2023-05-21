class Solution {
public:
    
    queue<pair<pair<int,int>,int>> q;
    
    void dfs(vector<vector<int>>& grid, int x, int y, int row, int col, vector<vector<bool>> &vis){
        if(x<0 || x>=row || y<0 || y>=col || vis[x][y] || grid[x][y]==0) return;
        vis[x][y] = true;
        grid[x][y] = 0;
        q.push({{x,y},0});
        
        int dx[] = {0,1,0,-1};
        int dy[] = {1,0,-1,0};
        
        for(int i=0;i<4;++i){
            int x1 = x+dx[i], y1 = y+dy[i];
            if(x1<0 || x1>=row || y1<0 || y1>=col || vis[x1][y1] || grid[x1][y1]==0) continue;
            dfs(grid,x1,y1,row,col,vis);
        }
        return;
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        
        int row = grid.size();
        int col = grid[0].size();
        bool flag = false;
        
        vector<vector<bool>> vis(row,vector<bool>(col,false));
        
        for(int i=0;i<row;++i){
            for(int j=0;j<col;++j){
                if(!vis[i][j] && grid[i][j]==1){
                    dfs(grid,i,j,row,col,vis);
                    flag=true;
                    break;
                }
            }
            if(flag) break;
        }
        
        int dx[] = {0,1,0,-1};
        int dy[] = {1,0,-1,0};

        while(!q.empty()){ 
            int x = q.front().first.first;
            int y = q.front().first.second;
            int dis = q.front().second;
            q.pop();

            for(int i=0;i<4;++i){
                int x1 = x+dx[i];
                int y1 = y+dy[i];

                if(x1<0 || x1>=row || y1<0 || y1>=col || vis[x1][y1]) continue;

                if(grid[x1][y1]==1) return dis;
                else {
                    vis[x1][y1] = true;
                    q.push({{x1,y1},dis+1});
                }
            }
        }
        return -1;
    }
};