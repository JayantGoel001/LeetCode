class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> v;
        for(int i=0;i<matrix.size();i++){
            int minj = 0;
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][minj] > matrix[i][j]){
                    minj = j;  
                }
            }
            bool found = true;
            for(int _i = 0;_i<matrix.size();_i++){
                if(matrix[i][minj] < matrix[_i][minj]){
                    found = false;
                    break;
                }
            }
            if(found){
                v.push_back(matrix[i][minj]);
            }
        }
        return v;
    }
};