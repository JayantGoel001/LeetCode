class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        // Map to store the index of each number in the arr
        unordered_map<int, int> numToIndex;
        for (int i = 0; i < arr.size(); i++) {
            numToIndex[arr[i]] = i;
        }

        int result = INT_MAX;
        int numRows = mat.size();
        int numCols = mat[0].size();

        // Check for the earliest row to be completely painted
        for (int row = 0; row < numRows; row++) {
            // Tracks the greatest index in this column
            int lastElementIndex = INT_MIN;
            for (int col = 0; col < numCols; col++) {
                int indexVal = numToIndex[mat[row][col]];
                lastElementIndex = max(lastElementIndex, indexVal);
            }
            // Update result with the minimum index where this row is fully
            // painted
            result = min(result, lastElementIndex);
        }

        // Check for the earliest column to be completely painted
        for (int col = 0; col < numCols; col++) {
            // Tracks the greatest index in this column
            int lastElementIndex = INT_MIN;
            for (int row = 0; row < numRows; row++) {
                int indexVal = numToIndex[mat[row][col]];
                lastElementIndex = max(lastElementIndex, indexVal);
            }
            // Update result with the minimum index where this column is fully
            // painted
            result = min(result, lastElementIndex);
        }

        return result;
    }
};