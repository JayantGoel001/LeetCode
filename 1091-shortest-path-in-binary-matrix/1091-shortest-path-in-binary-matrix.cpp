#define pii pair<int,int> 
class Solution {
public:
    bool isSafe(vector<vector<int>>& grid,int i,int j,int n){
        return i >= 0 && j >= 0 && i < n && j < n && grid[i][j] == 0;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1){
            return -1;
        }
        pii xy[8] = {{0,1},{0,-1},{1,0},{-1,0},{-1,-1},{-1,1},{1,-1},{1,1}};
        queue<pii> q;
        
        q.push({0,0});
        grid[0][0] = 1;
        while(!q.empty()){
            pii top = q.front();
            q.pop();
            
            if(top.first == n-1 && top.second == n-1){
                return grid[top.first][top.second];
            }
            
            for(auto it : xy){
                if(isSafe(grid,top.first + it.first,top.second + it.second,n)){
                    q.push({top.first + it.first, top.second + it.second});
                    grid[top.first + it.first][top.second + it.second] = grid[top.first][top.second] + 1;
                }
            }    
        }
        return -1;
    }
};