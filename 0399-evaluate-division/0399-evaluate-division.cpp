class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,int> mp;
        int size = 1;
        for(auto it : equations) {
            if (!mp[it[0]]) mp[it[0]] = size++;
            if (!mp[it[1]]) mp[it[1]] = size++;
        }

        vector<vector<double>> grid(size, vector<double> (size, -1));

        for(int i=0;i<values.size();i++) {
            grid[mp[equations[i][0]]][mp[equations[i][1]]] = values[i];
            grid[mp[equations[i][1]]][mp[equations[i][0]]] = 1 / values[i];
        }

        for(int k=1;k<size;k++) {
            for(int i=1;i<size;i++) {
                for(int j=1;j<size;j++) {
                    if (grid[i][j] != -1 || grid[i][k] == -1 || grid[k][j] == -1) continue;

                    grid[i][j] = grid[i][k] * grid[k][j];
                }
            }
        }
        vector<double> res;
        for(auto it : queries) {
            if (!mp[it[0]] || !mp[it[1]]) {
                res.push_back(-1.0);
                continue;
            }

            res.push_back(grid[mp[it[0]]][mp[it[1]]]);
        }

        return res;
    }
};