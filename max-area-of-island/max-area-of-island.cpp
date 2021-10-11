#define pii pair<int,int>
class Solution {
public:
    bool isSafe(int i,int j,int n,int m){
        return i>=0 && i < n && j>=0 && j < m;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        queue<pii> q;
        
        int n = grid.size();
        int m = grid[0].size();
        
        int X[] = {-1,0,1,0};
        int Y[] = {0,1,0,-1};
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){

                    int area = 0;
                    q.push({i,j});
                    
                    while(!q.empty()){
                        pii top = q.front();
                        q.pop();
                        
                        if(grid[top.first][top.second] == 1){
                            area++;
                            grid[top.first][top.second] = 0;
                            
                            for(int k=0;k<4;k++){
                                if(isSafe(top.first+X[k],top.second+Y[k],n,m) && grid[top.first + X[k]][top.second + Y[k]] == 1){
                                    q.push({top.first+X[k],top.second+Y[k]});
                                }
                            }
                        }
                    }
                    maxArea = max(maxArea,area);
                }
            }
        }
        return maxArea;
    }
};