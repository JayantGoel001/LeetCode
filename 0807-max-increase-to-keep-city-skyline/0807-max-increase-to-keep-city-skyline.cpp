class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> v(n, 0);
        vector<int> h(n, 0);
        
        for(int i=0;i<n;i++){
            int maxi = 0;
            for(auto it : grid[i]){
                maxi = max(maxi,it);
            }
            v[i] = maxi;
        }
        
        for(int j=0;j<n;j++){
            int maxi = 0;
            for(int i=0;i<n;i++){
                maxi = max(maxi, grid[i][j]);
            }
            h[j] = maxi;
        }
        
        int sum = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                sum += min(v[i], h[j]) - grid[i][j];
            }
        }
        return sum;
    }
};