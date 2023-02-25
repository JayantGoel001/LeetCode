class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        vector<vector<int>> v;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                v.push_back({i, j});
            }
        }
        auto cmp = [&](vector<int> &v1, vector<int> &v2) -> bool{
            int dist1 = abs(v1[0] - rCenter) + abs(v1[1] - cCenter);
            int dist2 = abs(v2[0] - rCenter) + abs(v2[1] - cCenter);
            
            return dist1 < dist2;
        };
        sort(v.begin(), v.end(), cmp);
        return v;
    }
};