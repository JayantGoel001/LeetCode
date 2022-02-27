class Solution {
public:
    
    bool DFS(vector<vector<int>>& grid,int i,int j,int n,int m){
        if(i >= 0 && j >= 0 && i < n && j < m){
            if(grid[i][j] == 1){
                return true;
            }
            grid[i][j] = 1;
            
            bool b1 = DFS(grid,i - 1,j,n,m);
            bool b2 = DFS(grid,i + 1,j,n,m);
            bool b3 = DFS(grid,i,j - 1,n,m);
            bool b4 = DFS(grid,i,j + 1,n,m);
            
            return b1 && b2 && b3 && b4;
        }
        return false;
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int count = 0;
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 0){
                    count += DFS(grid,i,j,n,m);
                }
            }
        }
        return count;
    }
};