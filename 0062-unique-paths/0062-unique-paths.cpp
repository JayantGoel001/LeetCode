class Solution {
public:
    vector<vector<int>> v;
    int getPaths(int m, int n){
        if(m == 1 || n == 1){
            return 1;
        }
        if(v[m][n] == 0){
            v[m][n] = getPaths(m - 1, n) + getPaths(m, n - 1);
        }
        return v[m][n];
    }
    int uniquePaths(int m, int n) {
        v.resize(m + 1, vector<int> (n + 1, 0));
        
        return getPaths(m,n);
    }
};