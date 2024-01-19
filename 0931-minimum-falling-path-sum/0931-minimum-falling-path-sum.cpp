class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<m;j++){
                int x = matrix[i+1][j];
                if(j > 0){
                    x = min(x,matrix[i+1][j-1]);
                }
                if(j < m-1){
                    x = min(x,matrix[i+1][j+1]);
                }
                matrix[i][j] += x;
            }
        }
        
        int mini = INT_MAX;
        for(int i=0;i<m;i++){
            mini = min(mini,matrix[0][i]);
        }
        return mini;
    }
};