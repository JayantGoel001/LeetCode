#define pii pair<int,int> 
class Solution {
public:
    bool isSafe(int i,int j,int n,int m,vector<vector<int>>& grid){
        return i >= 0 && j >= 0 && i < n && j<m && grid[i][j];
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxi = 0;
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pii> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    q.push({i,j});
                    int area = 0;
                    while(!q.empty()){
                        pii top = q.front();
                        q.pop();
                        
                        if(grid[top.first][top.second] == 1){
                            area++;
                            
                            grid[top.first][top.second] = 0;
                            
                            if(isSafe(top.first-1,top.second,n,m,grid)){
                                q.push({top.first-1,top.second});
                            }
                            if(isSafe(top.first+1,top.second,n,m,grid)){
                                q.push({top.first+1,top.second});
                            }
                            if(isSafe(top.first,top.second-1,n,m,grid)){
                                q.push({top.first,top.second-1});
                            }
                            if(isSafe(top.first,top.second+1,n,m,grid)){
                                q.push({top.first,top.second+1});
                            }
                        }
                    }
                    maxi = max(maxi,area);
                }
            }
        }
        return maxi;
    }
};