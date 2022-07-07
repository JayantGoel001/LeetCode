class Solution {
public:
    bool valid(int rsize,int csize,int r,int c){
        if(rsize<=r||csize<=c||c<0||r<0)return false;
        return true;
    }
    int DFS(vector<vector<int>>& grid,int r,int c){
        if(r==grid.size())return c;
        if(valid(grid.size(),grid[0].size(),r,c)){
            if(grid[r][c]==1){
                if(valid(grid.size(),grid[0].size(),r,c+1)&&grid[r][c+1]==1){
                    return DFS(grid,r+1,c+1);
                }
            }else{
                if(valid(grid.size(),grid[0].size(),r,c-1)&&grid[r][c-1]==-1){
                    return DFS(grid,r+1,c-1);
                }
            }
        }
        return -1;
    }
    vector<int> findBall(vector<vector<int>>& grid){
        int row = grid.size(),col = grid[0].size();
        vector<int>ans(col,0);
        for(int c = 0;c<col;c++){
            ans[c] = DFS(grid,0,c);
        }
    return ans;
    }
};