class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int M = land.size(), N = land[0].size();
        vector<vector<int>> res;
        
        for (int row1 = 0; row1 < M; row1++) {
            for (int col1 = 0; col1 < N; col1++) {
                if (land[row1][col1]) {
                    int x = row1, y = col1;
                    
                    for (x = row1; x < M && land[x][col1]; x++) {
                        for (y = col1; y < N && land[x][y]; y++) {
                            land[x][y] = 0;
                        }
                    }

                    res.push_back({row1, col1, x - 1, y - 1});
                }
            }
        }
        return res;
    }
};