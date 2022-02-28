class Solution {
public:
    int count = 0;
    void DFS(vector<vector<int>>& grid,int i,int j,int n,int m){
        if(i>=0 && j>=0 && i < n && j < m && grid[i][j] == 1){
            grid[i][j] = 0;
            count--;
            
            DFS(grid,i-1,j,n,m);
            DFS(grid,i,j-1,n,m);
            DFS(grid,i+1,j,n,m);
            DFS(grid,i,j+1,n,m);
        }
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                count += grid[i][j];
            }
        }
        
        for(int i=0;i<n;i++){
            if(grid[i][0] == 1){
                DFS(grid,i,0,n,m);
            }
            if(grid[i][m - 1] == 1){
                DFS(grid,i,m - 1,n,m);
            }
        }
        for(int j=0;j<m;j++){
            if(grid[0][j] == 1){
                DFS(grid,0,j,n,m);
            }
            if(grid[n - 1][j] == 1){
                DFS(grid,n - 1,j,n,m);
            }
        }
        return count;
    }
};