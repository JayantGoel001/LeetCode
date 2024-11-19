class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = 0;
        long long currentSum = 0;
        int begin = 0;
        int end = 0;

        unordered_map<int, int> numToIndex;

        while (end < nums.size()) {
            int currNum = nums[end];
            int lastOccurrence =
                (numToIndex.count(currNum) ? numToIndex[currNum] : -1);

            // if current window already has number or if window is too big,
            // adjust window
            while (begin <= lastOccurrence || end - begin + 1 > k) {
                currentSum -= nums[begin];
                begin++;
            }
            numToIndex[currNum] = end;
            currentSum += nums[end];
            if (end - begin + 1 == k) {
                ans = max(ans, currentSum);
            }
            end++;
        }
        return ans;
    }
};