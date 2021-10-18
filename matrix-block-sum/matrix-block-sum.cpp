class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<int>> prefixSum(n,vector<int> (m,0));
        prefixSum[0][0] = mat[0][0];
        for(int i=1;i<n;i++){
            prefixSum[i][0] = mat[i][0] + prefixSum[i-1][0];
        }
        for(int j=1;j<m;j++){
            prefixSum[0][j] = mat[0][j] + prefixSum[0][j-1];
        }
        
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                prefixSum[i][j] = mat[i][j] + prefixSum[i][j-1] + prefixSum[i-1][j] - prefixSum[i-1][j-1];
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int low_i = max(0,i-k);
                int low_j = max(0,j-k);
                
                int upp_i = min(n-1,i+k);
                int upp_j = min(m-1,j+k);
                
                mat[i][j] = prefixSum[upp_i][upp_j] - ((low_i == 0)? 0 : prefixSum[low_i - 1][upp_j]) - ((low_j == 0) ? 0 : prefixSum[upp_i][low_j - 1]) + ((low_i == 0 || low_j == 0) ? 0 : prefixSum[low_i-1][low_j-1]);
            }
        }
        return mat;
    }
};