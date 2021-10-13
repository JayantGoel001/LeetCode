#define pii pair<int,int>
class Solution {
public:
    bool isSafe(int i,int j,int n,int m){
        return i>=0 && i<n && j>=0 && j<m;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pii> q;
        int t = 0;
        
        int n = grid.size();
        int m = grid[0].size();
        
        int X[] = {0,0,-1,1};
        int Y[] = {1,-1,0,0};
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            int size = q.size();
            int x = 0;
            for(int i=0;i<size;i++){
                pii top = q.front();
                q.pop();


                if(grid[top.first][top.second] == 2){
                    for(int k=0;k<4;k++){
                        if(isSafe(top.first + X[k],top.second + Y[k],n,m) && grid[top.first + X[k]][top.second + Y[k]] == 1){
                            grid[top.first + X[k]][top.second + Y[k]] = 2;
                            q.push({top.first + X[k],top.second + Y[k]});
                            x++;
                        }
                    }
                }
            }
            if(x!=0){
                t++;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return t;
    }
};