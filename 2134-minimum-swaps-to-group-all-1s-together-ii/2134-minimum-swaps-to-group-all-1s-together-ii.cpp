class Solution {
public:
    int minSwaps(vector<int>& nums) {
        // Initialize minimum swaps to a large value
        int minimumSwaps = INT_MAX;

        // Calculate the total number of 1s in the array
        int totalOnes = accumulate(nums.begin(), nums.end(), 0);

        // Initialize the count of 1s in the current window
        int onesCount = nums[0];
        int end = 0;

        // Slide the window across the array
        for (int start = 0; start < nums.size(); ++start) {
            // Adjust onesCount by removing the element that is sliding out of
            // the window
            if (start != 0) {
                onesCount -= nums[start - 1];
            }

            // Expand the window to the right until it reaches the desired size
            while (end - start + 1 < totalOnes) {
                end++;
                onesCount += nums[end % nums.size()];
            }

            // Update the minimum number of swaps needed
            minimumSwaps = min(minimumSwaps, totalOnes - onesCount);
        }

        return minimumSwaps;
    }
};