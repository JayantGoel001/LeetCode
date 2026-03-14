class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<string,int> mp1, mp2;

        for(int i=0;i<grid.size();i++) {
            string str = "";
            for(int j=0;j<grid.size();j++) {
                str += to_string(grid[i][j]);
                str.push_back('.');
            }

            mp1[str]++;
        }

        int count = 0;
        for(int j=0;j<grid.size();j++) {
            string str = "";
            for(int i=0;i<grid.size();i++) {
                str += to_string(grid[i][j]);
                str.push_back('.');
            }
            count += mp1[str];
        }

        return count;
    }
};