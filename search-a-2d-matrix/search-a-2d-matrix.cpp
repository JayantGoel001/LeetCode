class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size();
        int c = matrix[0].size();
        
        
        if(target < matrix[0][0] || target > matrix[r-1][c-1]){
            return false;
        }
        int low = 0;
        int high = r - 1;
        int ans = 0;
        while(low <= high){
            int mid = (low + high)/2;
            if(matrix[mid][0] == target){
                return true;
            }else if(matrix[mid][0] < target){
                ans = mid;
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        int pos = lower_bound(matrix[ans].begin(),matrix[ans].end(),target) - matrix[ans].begin();
        return pos != c && matrix[ans][pos] == target;
    }
};