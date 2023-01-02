class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        vector<priority_queue<int>> v(grid.size());
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                v[i].push(grid[i][j]);
            }
        }
        int ans = 0;
        for(int j=0;j<grid[0].size();j++){
            int maxi = 0;
            for(int i=0;i<grid.size();i++){
                maxi = max(maxi,v[i].top());
                v[i].pop();
            }
            ans += maxi;
        }
        return ans;
    }
};