#define pii pair<int,int>
class Solution {
public:
    bool isSafe(vector<vector<char>>& grid,int i,int j,int n,int m){
        return i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == '1';
    }
    int numIslands(vector<vector<char>>& grid) {
        queue<pii> q;
        
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1'){
                    q.push({i,j});
                    count++;
                    
                    while(!q.empty()){
                        pii top = q.front();
                        q.pop();
                        
                        if(grid[top.first][top.second] == '1'){
                            grid[top.first][top.second] = '0';
                            
                            if(isSafe(grid,top.first - 1,top.second,n,m)){
                                q.push({top.first - 1,top.second});
                            }

                            if(isSafe(grid,top.first + 1,top.second,n,m)){
                                q.push({top.first + 1,top.second});
                            }

                            if(isSafe(grid,top.first,top.second - 1,n,m)){
                                q.push({top.first,top.second - 1});
                            }

                            if(isSafe(grid,top.first,top.second + 1,n,m)){
                                q.push({top.first,top.second + 1});
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};