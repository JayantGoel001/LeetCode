class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int minLength = INT_MAX;
        int windowStart = 0;
        int windowEnd = 0;
        vector<int> bitCounts(32,
                              0);  // Tracks count of set bits at each position

        // Expand window until end of array
        while (windowEnd < nums.size()) {
            // Add current number to window
            updateBitCounts(bitCounts, nums[windowEnd], 1);

            // Contract window while OR value is valid
            while (windowStart <= windowEnd &&
                   convertBitCountsToNumber(bitCounts) >= k) {
                // Update minimum length found so far
                minLength = min(minLength, windowEnd - windowStart + 1);

                // Remove leftmost number and shrink window
                updateBitCounts(bitCounts, nums[windowStart], -1);
                windowStart++;
            }

            windowEnd++;
        }

        return minLength == INT_MAX ? -1 : minLength;
    }

private:
    // Updates bit count array when adding/removing a number from window
    void updateBitCounts(vector<int>& bitCounts, int number, int delta) {
        for (int bitPosition = 0; bitPosition < 32; bitPosition++) {
            // Check if bit is set at current position
            if ((number >> bitPosition) & 1) {
                bitCounts[bitPosition] += delta;
            }
        }
    }

    // Converts bit count array back to number using OR operation
    int convertBitCountsToNumber(const vector<int>& bitCounts) {
        int result = 0;
        for (int bitPosition = 0; bitPosition < 32; bitPosition++) {
            if (bitCounts[bitPosition] != 0) {
                result |= 1 << bitPosition;
            }
        }
        return result;
    }
};