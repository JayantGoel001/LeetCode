class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<vector<int>> mat(n,vector<int>(m,INT_MAX - 100000));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]!=0){
                    if(i > 0){
                        mat[i][j] = min(mat[i][j],mat[i-1][j] + 1);
                    }
                    if(j > 0){
                        mat[i][j] = min(mat[i][j],mat[i][j-1] + 1);
                    }
                }else{
                    mat[i][j] = 0;
                }
            }
        }
        
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(matrix[i][j]!=0){
                    if(i < n-1){
                        mat[i][j] = min(mat[i][j],mat[i+1][j] + 1);
                    }
                    if(j < m-1){
                        mat[i][j] = min(mat[i][j],mat[i][j+1] + 1);
                    }
                }else{
                    mat[i][j] = 0;
                }
            }
        }
        
        return mat;
    }
};