class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        
        vector<vector<int>> res;
        
        vector<vector<bool>> pac(n, vector<bool> (m, false)), atl(n, vector<bool> (m, false));
        
        for(int i=0;i<n;i++){
            DFS(heights, i, 0, pac, n, m, heights[i][0]);
            DFS(heights, i, m - 1, atl, n, m, heights[i][m - 1]);
        }
        
        for(int i=0;i<m;i++){
            DFS(heights,0,i,pac,n,m,heights[0][i]);
            DFS(heights,n - 1,i,atl,n,m,heights[n - 1][i]);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pac[i][j] && atl[i][j]){
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
    void DFS(vector<vector<int>>& heights,int i,int j,vector<vector<bool>> &v,int n,int m,int prev){
        if(i >= 0 && j >= 0 && i < n && j < m && !v[i][j] && heights[i][j] >= prev){
            v[i][j] = true;
            DFS(heights, i - 1, j, v, n, m, heights[i][j]);
            DFS(heights, i + 1, j, v, n, m, heights[i][j]);
            DFS(heights, i, j + 1, v, n, m, heights[i][j]);
            DFS(heights, i, j - 1, v, n, m, heights[i][j]);
        }
    }
};