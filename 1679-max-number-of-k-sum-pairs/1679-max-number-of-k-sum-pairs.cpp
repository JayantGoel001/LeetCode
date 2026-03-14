class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int low = 0;
        int high = nums.size() - 1;
        int count = 0;
        while(low < high) {
            if (nums[low] + nums[high] == k) {
                count++;
                low++;
                high--;
            } else if (nums[low] + nums[high] < k) {
                low++;
            } else {
                high--;
            }
        }

        return count;
    }
};