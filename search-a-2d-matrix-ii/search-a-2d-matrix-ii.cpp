class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int size = matrix.size();
        int n = matrix[0].size();
        
        for(int i=0;i<size;i++){
            int pos = lower_bound(matrix[i].begin(),matrix[i].end(),target) - matrix[i].begin();
            
            if(pos != n && matrix[i][pos] == target){
                return true;
            }
        }
        return false;
    }
};