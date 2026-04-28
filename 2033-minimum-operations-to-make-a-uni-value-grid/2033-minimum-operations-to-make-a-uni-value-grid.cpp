class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        // Initialize an empty array to store all numbers from the grid
        vector<int> numsArray;
        int result = 0;

        // Flatten the grid into numsArray
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[0].size(); col++) {
                // If any element has a different remainder than the first
                // element, it is impossible to make all elements equal, so
                // return -1
                if (grid[row][col] % x != grid[0][0] % x) return -1;
                numsArray.push_back(grid[row][col]);
            }
        }

        // Sort numsArray in non-decreasing order to facilitate efficient
        // operations
        sort(numsArray.begin(), numsArray.end());

        int length = numsArray.size();
        int prefixIndex = 0;
        int suffixIndex = length - 1;

        // Gradually move prefixIndex and suffixIndex towards the middle
        while (prefixIndex < suffixIndex) {
            // If the prefix of equal elements is shorter than the suffix
            if (prefixIndex < length - suffixIndex - 1) {
                // Calculate the number of operations required to extend the
                // prefix
                int prefixOperations =
                    (prefixIndex + 1) *
                    (numsArray[prefixIndex + 1] - numsArray[prefixIndex]) / x;

                result += prefixOperations;
                // Move the prefix index forward
                prefixIndex++;
            } else {
                // Calculate the number of operations required to extend the
                // suffix
                int suffixOperations =
                    (length - suffixIndex) *
                    (numsArray[suffixIndex] - numsArray[suffixIndex - 1]) / x;

                result += suffixOperations;
                // Move the suffix index backward
                suffixIndex--;
            }
        }

        return result;
    }
};