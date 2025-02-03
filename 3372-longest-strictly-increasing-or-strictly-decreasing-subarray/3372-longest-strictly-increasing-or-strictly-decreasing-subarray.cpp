class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        // Track current lengths of increasing and decreasing sequences
        int incLength = 1, decLength = 1;
        int maxLength = 1;

        // Iterate through array comparing adjacent elements
        for (int pos = 0; pos < nums.size() - 1; pos++) {
            if (nums[pos + 1] > nums[pos]) {
                // If next element is larger, extend increasing sequence
                incLength++;
                decLength = 1;  // Reset decreasing sequence
            } else if (nums[pos + 1] < nums[pos]) {
                // If next element is smaller, extend decreasing sequence
                decLength++;
                incLength = 1;  // Reset increasing sequence
            } else {
                // If elements are equal, reset both sequences
                incLength = 1;
                decLength = 1;
            }

            // Update max length considering both sequences
            maxLength = max(maxLength, max(incLength, decLength));
        }
        return maxLength;
    }
};