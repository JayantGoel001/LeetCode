class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }

private:
    int atMost(vector<int>& nums, int k) {
        int windowSize = 0, subarrays = 0, start = 0;

        for (int end = 0; end < nums.size(); end++) {
            windowSize += nums[end] % 2;
            // Find the first index start where the window has exactly k odd
            // elements.
            while (windowSize > k) {
                windowSize -= nums[start] % 2;
                start++;
            }
            // Increment number of subarrays with end - start + 1.
            subarrays += end - start + 1;
        }

        return subarrays;
    }
};