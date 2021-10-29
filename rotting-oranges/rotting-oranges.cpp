#define pii pair<int,int>
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pii> q;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
            }
        }
        pii XY[4] = {{-1,0},{1,0},{0,1},{0,-1}};
        
        int count = 0;
        while(!q.empty()){
            int size = q.size();
            int flag = 0;
            for(int i=0;i<size;i++){
                pii top = q.front();
                q.pop();

                if(grid[top.first][top.second] == 2){
                    grid[top.first][top.second] = 0;
                    
                    for(int i=0;i<4;i++){
                        int xx = top.first + XY[i].first;
                        int yy = top.second + XY[i].second;

                        if(xx>=0 && xx < n && yy>=0 && yy < m && grid[xx][yy] == 1){
                            flag++;
                            grid[xx][yy] = 2;
                            q.push({xx,yy});
                        }
                    }
                }   
            }
            if(flag){
                count++;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return count;
    }
};