class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int sum = 0;
        for (auto it: nums) sum += it;

        int lSum = 0;
        int count = 0;
        for(int i=0;i<nums.size();i++) {
            if (nums[i] == 0 && abs(sum - 2 * lSum) <= 1) {
                count += (2 - abs(sum - 2 * lSum));
            }
            lSum += nums[i];
        }

        return count;
    }
};