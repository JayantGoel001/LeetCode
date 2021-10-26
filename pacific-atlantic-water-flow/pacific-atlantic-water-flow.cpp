class Solution {
public:
    vector<vector<int>> vis;
    vector<vector<int>> res;
    
    void DFS(vector<vector<int>>& heights,int i,int j,int x,int n,int m,int prev){
        if(i>=0 && i<n && j>=0 && j<m && prev <= heights[i][j] && (vis[i][j]&x) != x){
            vis[i][j] |= x;
            if(vis[i][j] == 3){
                res.push_back({i,j});
            }
            DFS(heights,i+1,j,x,n,m,heights[i][j]);
            DFS(heights,i-1,j,x,n,m,heights[i][j]);
            DFS(heights,i,j+1,x,n,m,heights[i][j]);
            DFS(heights,i,j-1,x,n,m,heights[i][j]);
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        
        vis.resize(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++){
            DFS(heights,i,0,1,n,m,INT_MIN);
            DFS(heights,i,m-1,2,n,m,INT_MIN);
        }
        
        for(int j=0;j<m;j++){
            DFS(heights,0,j,1,n,m,INT_MIN);
            DFS(heights,n-1,j,2,n,m,INT_MIN);
        }
        return res;
    }
};