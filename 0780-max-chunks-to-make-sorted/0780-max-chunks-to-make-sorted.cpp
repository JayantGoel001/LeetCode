class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int chunks = 0, maxElement = 0;

        // Iterate over the array
        for (int i = 0; i < n; i++) {
            // Update maxElement
            maxElement = max(maxElement, arr[i]);

            if (maxElement == i) {
                // All values in range [0, i] belong to the prefix arr[0:i];
                // a new chunk can be formed
                chunks++;
            }
        }

        return chunks;
    }
};