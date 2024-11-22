class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        // Map to store frequency of each pattern
        unordered_map<string, int> patternFrequency;

        for (auto& currentRow : matrix) {
            string patternBuilder = "";

            // Convert row to pattern relative to its first element
            for (int col = 0; col < currentRow.size(); col++) {
                // 'T' if current element matches first element, 'F' otherwise
                if (currentRow[0] == currentRow[col]) {
                    patternBuilder += "T";
                } else {
                    patternBuilder += "F";
                }
            }

            // Convert pattern to string and update its frequency in map
            patternFrequency[patternBuilder]++;
        }

        // Find the pattern with maximum frequency
        int maxFrequency = 0;
        for (auto& entry : patternFrequency) {
            maxFrequency = max(entry.second, maxFrequency);
        }

        return maxFrequency;
    }
};