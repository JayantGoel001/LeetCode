class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int start = 0;
        int prefixZeros = 0;
        int currentSum = 0;
        int totalCount = 0;
        
        // Loop through the array using end pointer
        for (int end = 0; end < nums.size(); ++end) {
            // Add current element to the sum
            currentSum += nums[end];
            
            // Slide the window while condition is met
            while (start < end && (nums[start] == 0 || currentSum > goal)) {
                if (nums[start] == 1) {
                    prefixZeros = 0;
                } else {
                    prefixZeros += 1;
                }
                
                currentSum -= nums[start];
                start += 1;
            }
            
            // Count subarrays when window sum matches the goal
            if (currentSum == goal) {
                totalCount += 1 + prefixZeros;
            }
        }
        
        return totalCount;
    }
};