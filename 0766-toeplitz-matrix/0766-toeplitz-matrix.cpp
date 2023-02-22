class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for(int i=1;i<matrix.size();i++){
            for(int j=1;j<matrix[0].size();j++){
                if(matrix[i - min(i, j)][j - min(i,j)] != matrix[i][j]){
                    return false;
                }
            }
        }
        return true;
    }
};