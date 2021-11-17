class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v;
        v.push_back({1});
        for(int i=1;i<numRows;i++){
            vector<int> _v;
            _v.push_back(1);
            
            for(int j=1;j<i;j++){
                _v.push_back(v.back()[j] + v.back()[j-1]);
            }
            
            _v.push_back(1);
            v.push_back(_v);
        }
        return v;
    }
};