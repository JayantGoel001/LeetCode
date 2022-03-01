#define pii pair<int,int> 
class Solution {
public:
    bool isSafe(vector<vector<int>>& grid,int i,int j,int n,int m){
        return i>=0 && j>=0 && i < n && j < m && grid[i][j] == 0;
    }
    int maxDistance(vector<vector<int>>& grid) {
        queue<pii> q;
        int n = grid.size();
        int m = grid[0].size();
        
        int maxi = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    q.push({i-1, j});
                    q.push({i+1, j});
                    q.push({i, j-1});
                    q.push({i, j+1});
                }
            }
        }
        int steps = 0;     
        while(!q.empty()){
            int size = q.size();
            steps++;
            while(size--){
                pii top = q.front();
                q.pop();

                if(isSafe(grid,top.first,top.second,n,m)){
                    grid[top.first][top.second] = steps;
                    
                    q.push({top.first-1,top.second});
                    q.push({top.first+1,top.second});
                    q.push({top.first,top.second-1});
                    q.push({top.first,top.second+1});
                }
            }
        }
        return steps != 1 ? steps - 1 : -1;
    }
};