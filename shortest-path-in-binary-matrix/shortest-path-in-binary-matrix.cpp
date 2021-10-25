#define pii pair<int,int> 
class Solution {
public:
    bool isSafe(int i,int j,int n,int m,vector<vector<int>>& grid){
        return i>=0 && j>=0 && i < n  && j < m && grid[i][j] == 0;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        if(grid[0][0] == 1 || grid[n-1][m-1] == 1){
            return -1;
        }
        
        queue<pii> q;
        
        vector<pii> XY = {{0,1},{0,-1},{1,0},{-1,0},{1,-1},{-1,1},{1,1},{-1,-1}};
        q.push({0,0});
        grid[0][0] = 1;
        
        while(!q.empty()){
            pii top = q.front();
            q.pop();
            
            if(top.first == n-1 && top.second == m-1){
                return grid[n-1][m-1];
            }
            for(auto it : XY){
                if(isSafe(top.first + it.first,top.second + it.second,n,m,grid)){
                    q.push({top.first + it.first,top.second + it.second});
                    grid[top.first + it.first][top.second + it.second] = grid[top.first][top.second] + 1;
                }
            }
        }
        return -1;
    }
};