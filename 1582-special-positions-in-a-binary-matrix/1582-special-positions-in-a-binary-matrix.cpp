class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        vector<int> row(mat.size(), 0);
        vector<int> col(mat[0].size(), 0);
        
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                row[i] += mat[i][j];
                col[j] += mat[i][j];
            }
        }
        int count = 0;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                count += (mat[i][j] && row[i] == 1 && col[j] == 1);
            }
        }
        
        return count;
    }
};