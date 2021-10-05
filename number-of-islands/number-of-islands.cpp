#define pii pair<int,int>
class Solution {
public:
    bool isSafe(int i,int j,vector<vector<char>>& grid,int n,int m){
        return i>=0 && i<n && j>=0 && j<m && grid[i][j] == '1';
    }
    int numIslands(vector<vector<char>>& grid) {
        queue<pii> q;
        
        int n = grid.size();
        int m = grid[0].size();
        
        int X[] = {-1,0,1,0};
        int Y[] = {0,1,0,-1};
        
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
                            grid[top.first][top.second] = '2';
                            
                            for(int i=0;i<4;i++){
                                if(isSafe(top.first+X[i],top.second+Y[i],grid,n,m)){
                                    q.push({top.first+X[i],top.second+Y[i]});
                                }
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};