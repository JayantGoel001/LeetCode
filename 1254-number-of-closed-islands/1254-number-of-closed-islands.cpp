#define pii pair<int,int>
class Solution {
public:
    bool isSafe(int x,int y,int n,int m){
        return x >= 0 && x < n && y >= 0 && y < m;
    }
    bool bfs(vector<vector<int>> &grid, int x, int y, int n, int m){
        queue<pii> q;
        q.push({x,y});

        bool isEdge = false;
        while(!q.empty()){
            pii top = q.front();
            q.pop();

            if(grid[top.first][top.second] == 0){
                grid[top.first][top.second] = 2;

                if(isSafe(top.first-1, top.second, n, m)){
                    if(grid[top.first-1][top.second] == 0){
                        q.push({top.first-1, top.second});
                    }
                }else{
                    isEdge = true;
                }
                if(isSafe(top.first, top.second-1,n,m)){
                    if(grid[top.first][top.second-1] == 0){
                        q.push({top.first, top.second-1});
                    }
                }else{
                    isEdge = true;
                }
                if(isSafe(top.first+1, top.second,n,m)){
                    if(grid[top.first+1][top.second] == 0){
                        q.push({top.first+1, top.second});
                    }
                }else{
                    isEdge = true;
                }
                if(isSafe(top.first, top.second+1,n,m)){
                    if(grid[top.first][top.second+1] == 0){
                     q.push({top.first, top.second+1});
                    }
                }else{
                    isEdge = true;
                }
            }
        }
        return isEdge;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 0){
                    count += !bfs(grid, i, j, n, m);
                }
            }
        }
        return count;
    }
};