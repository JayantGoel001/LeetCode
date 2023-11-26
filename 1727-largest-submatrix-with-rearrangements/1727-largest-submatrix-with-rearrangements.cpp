class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<pair<int,int>> prevHeights;
        int ans = 0;
        
        for (int row = 0; row < m; row++) {
            vector<pair<int,int>> heights;
            vector<bool> seen = vector(n, false);
            
            for (auto [height, col] : prevHeights) {
                if (matrix[row][col] == 1) {
                    heights.push_back({height + 1, col});
                    seen[col] = true;
                }
            }
            
            for (int col = 0; col < n; col++) {
                if (seen[col] == false && matrix[row][col] == 1) {
                    heights.push_back({1, col});
                }
            }
            
            for (int i = 0; i < heights.size(); i++) {
                ans = max(ans, heights[i].first * (i + 1));
            }
            
            prevHeights = heights;
        }

        return ans;
    }
};