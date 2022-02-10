class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = 0;
        int j = matrix.size()-1;
        int m = matrix[0].size() - 1;
        
        int mid = 0;
        while(i <= j){
            mid = (i + j)/2;
            
            if(matrix[mid][0] <= target && target <= matrix[mid][m]){
                break;
            }else if(matrix[mid][0] < target){
                i = mid + 1;
            }else{
                j = mid - 1;
            }
        }
        return binary_search(matrix[mid].begin(),matrix[mid].end(),target);
    }
};