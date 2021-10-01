class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int i = 0;
        int j = 0;
        int k = matrix.size()-1;
        int l = matrix[0].size()-1;
        int count = 0;
        
        int maxi = matrix.size() * matrix[0].size();
        vector<int> v;
        
        while(i<=k && j<=l){
            for(int x = j;x<=l;x++){
                v.push_back(matrix[i][x]);
                count++;
            }
            i++;
            if(count>=maxi){
                break;
            }
            for(int x = i;x<=k;x++){
                v.push_back(matrix[x][l]);
                count++;
            }
            l--;
            if(count>=maxi){
                break;
            }
            
            for(int x = l;x>=j;x--){
                v.push_back(matrix[k][x]);
                count++;
            }
            k--;
            if(count>=maxi){
                break;
            }
            for(int x = k;x>=i;x--){
                v.push_back(matrix[x][j]);
                count++;
            }
            j++;
            if(count>=maxi){
                break;
            }
        }
        return v;
    }
};