#define pii pair<int,int>
class Solution {
public:
    bool isSafe(int i,int j,int n,int m){
        return i>=0 && j>=0 && i<n && j<m;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        queue<pii> q; 
        
        int count = 0;
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    q.push({i,j});
                    
                    while(!q.empty()){
                        pii top = q.front();
                        q.pop();
                        if(grid[top.first][top.second] == 1){
                            grid[top.first][top.second] = 2;
                            
                            int x = 0;
                            if(isSafe(top.first,top.second - 1,n,m)){
                               if(grid[top.first][top.second-1] == 1){
                                    x++;
                                    q.push({top.first,top.second-1});
                               }else if(grid[top.first][top.second-1] == 2){
                                    x++;
                               }
                            }
                            if(isSafe(top.first,top.second + 1,n,m)){
                                if(grid[top.first][top.second+1] == 1){
                                    x++;
                                    q.push({top.first,top.second+1});
                                }else if(grid[top.first][top.second+1] == 2){
                                    x++;
                               }
                            }
                            if(isSafe(top.first - 1,top.second,n,m)){
                                if(grid[top.first-1][top.second] == 1){
                                    x++;
                                    q.push({top.first-1,top.second});
                                }else if(grid[top.first-1][top.second] == 2){
                                    x++;
                               }
                            }
                            if(isSafe(top.first + 1,top.second,n,m)){
                                if(grid[top.first+1][top.second] == 1){
                                    x++;
                                    q.push({top.first+1,top.second});
                                }else if(grid[top.first+1][top.second] == 2){
                                    x++;
                               }
                            }
                            count += (4 - x);
                        }
                    }
                }
            }
        }
        return count;
    }
};