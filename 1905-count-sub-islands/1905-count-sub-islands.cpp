#define pii pair<int,int>
class Solution {
public:
    bool isSafe(vector<vector<int>>& grid2,int i,int j,int n,int m){
        return i >= 0 && j >=0 && i < n && j < m && grid2[i][j];
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid2.size();
        int m = grid2[0].size();
        
        int count = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid2[i][j]){
                    queue<pii> q;
                    q.push({i, j});
                    bool success = true;
                    
                    while(!q.empty()){
                        pii top = q.front();
                        q.pop();
                        
                        if(grid1[top.first][top.second] == 0){
                            success = false;
                        }
                        
                        if(grid2[top.first][top.second]){
                            grid2[top.first][top.second] = 0;
                            
                            if(isSafe(grid2,top.first - 1,top.second,n,m)){
                                q.push({top.first - 1, top.second});
                            }
                            if(isSafe(grid2,top.first + 1,top.second,n,m)){
                                q.push({top.first + 1, top.second});
                            }
                            if(isSafe(grid2,top.first,top.second - 1,n,m)){
                                q.push({top.first,top.second - 1});
                            }
                            if(isSafe(grid2,top.first,top.second + 1,n,m)){
                                q.push({top.first,top.second + 1});                      
                            }
                        }
                        
                    }
                    count += success;
                }
            }
        }
        return count;
    }
};