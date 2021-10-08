class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int _r = mat.size();
        int _c = mat[0].size();
        
        if(_r * _c != r * c){
            return mat;
        }else{
            vector<vector<int>> v;
            vector<int> rV;
            int k = 0;
            for(int i=0;i<_r;i++){
                for(int j=0;j<_c;j++){
                    rV.push_back(mat[i][j]);
                    k++;
                    
                    if(k%c == 0){
                        v.push_back(rV);
                        k==0;
                        rV.clear();
                    }
                }
            }
            return v;
        }
    }
};