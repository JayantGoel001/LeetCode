class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        // If there's only one element, the maximum beauty is 1
        if (nums.size() == 1) return 1;

        int maxBeauty = 0;
        int maxValue = 0;

        // Find the maximum value in the array
        for (int num : nums) maxValue = max(maxValue, num);

        // Create an array to keep track of the count changes
        vector<int> count(maxValue + 1, 0);

        // Update the count array for each value's range [val - k, val + k]
        for (int num : nums) {
            count[max(num - k, 0)]++;  // Increment at the start of the range
            if (num + k + 1 <= maxValue)
                count[num + k + 1]--;  // Decrement after the range
        }

        int currentSum = 0;  // Tracks the running sum of counts
        // Calculate the prefix sum and find the maximum value
        for (int val : count) {
            currentSum += val;
            maxBeauty = max(maxBeauty, currentSum);
        }

        return maxBeauty;
    }
};