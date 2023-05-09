class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> v;
        int i = 0;
        int j = 0;
        int k = matrix.size();
        int l = matrix[0].size();
        int size = k * l;
        
        while(i < k && j < l){
            for(int x=j;x<l;x++){
                v.push_back(matrix[i][x]);
            }
            if(size == v.size()){
                break;
            }
            i++;
            for(int x = i;x<k;x++){
                v.push_back(matrix[x][l - 1]);
            }
            
            if(size == v.size()){
                break;
            }
            l--;
            for(int x = l - 1;x >= j;x--){
                v.push_back(matrix[k - 1][x]);
            }
            
            if(size == v.size()){
                break;
            }
            k--;
            for(int x = k - 1;x >= i;x--){
                v.push_back(matrix[x][j]);
            }
            j++;
        }
        return v;
    }
};