class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        
        if(r*c != mat.size() * mat[0].size()){
            return mat;
        }
        
        vector<vector<int>> v(r, vector<int>(c,0));
       
        int x = 0;
        int y = 0;
        
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                v[x][y] = mat[i][j];
            
                y++;
                if(y == c){
                    y = 0;
                    x++;
                }
            }
            
        }
        return v;
    }
};