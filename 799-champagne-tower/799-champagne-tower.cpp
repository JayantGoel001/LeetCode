class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> v(query_row + 2, vector<double> (query_row + 2, 0));
        v[0][0] = (double)poured;
        
        for(int i=0;i<=query_row;i++){
            for(int j=0;j<=i;j++){
                
                double x = (v[i][j] - 1.0)/2.0;
                
                if(x > 0){
                    v[i + 1][j] += x;
                    v[i + 1][j + 1] += x; 
                }
            }
        }
        return min(1.0,v[query_row][query_glass]);
    }
};