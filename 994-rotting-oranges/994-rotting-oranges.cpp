#define pii pair<int,int>
class Solution {
public:
    bool isSafe(int i,int j,int n,int m,vector<vector<int>>& grid){
        return i>=0 && j>=0 && i < n && j < m && grid[i][j] == 1;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pii> q;
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                    grid[i][j] = 0;
                }
            }
        }
        int time = 0;
        while(!q.empty()){
            int size = q.size();
            
            int x = 0;
            while(size--){
                pii top = q.front();
                q.pop();

                if(isSafe(top.first-1,top.second,n,m,grid)){
                    q.push({top.first-1,top.second});
                    grid[top.first-1][top.second] = 0;
                    x++;
                }

                if(isSafe(top.first,top.second-1,n,m,grid)){
                    q.push({top.first,top.second-1});
                    grid[top.first][top.second-1] = 0;
                    x++;
                }

                if(isSafe(top.first+1,top.second,n,m,grid)){
                    q.push({top.first+1,top.second});
                    grid[top.first+1][top.second] = 0;
                    x++;
                }

                if(isSafe(top.first,top.second+1,n,m,grid)){
                    q.push({top.first,top.second+1});
                    grid[top.first][top.second+1] = 0;
                    x++;
                }
            }
            if(x){
                time++;
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return time;
    }
};