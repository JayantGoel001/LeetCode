class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool isRow = false;
        bool isCol = false;
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        for(int i=0;i<n;i++){
            if(matrix[i][0]==0){
                isRow = true;
            }
        }
        for(int i=0;i<m;i++){
            if(matrix[0][i]==0){
                isCol = true;
            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][0] == 0 || matrix[0][j]==0){
                    matrix[i][j] = 0;
                }
            }
        }
        if(isRow){
            for(int i=0;i<n;i++){
                matrix[i][0] = 0;
            }
        }
        if(isCol){
            for(int i=0;i<m;i++){
                matrix[0][i] = 0;
            }
        }
    }
};