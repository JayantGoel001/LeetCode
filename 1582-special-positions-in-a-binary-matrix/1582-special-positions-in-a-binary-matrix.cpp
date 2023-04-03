class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int count = 0;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]){
                    int c = 0;
                    for(int k=0;k<mat.size();k++){
                        c += mat[k][j];
                    }
                    int r = 0;
                    for(int k=0;k<mat[0].size();k++){
                        r += mat[i][k];
                    }
                    count += (r == 1 && c == 1);
                }
            }
        }
        return count;
    }
};