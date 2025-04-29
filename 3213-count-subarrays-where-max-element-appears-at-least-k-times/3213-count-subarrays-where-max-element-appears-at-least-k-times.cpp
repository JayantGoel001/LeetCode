class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxElement = *max_element(nums.begin(), nums.end());
        vector<int> indexesOfMaxElements;
        long long ans  = 0;

        for (int index = 0; index < nums.size(); index++) {
            if (nums[index] == maxElement) {
                indexesOfMaxElements.push_back(index);
            }

            int freq = indexesOfMaxElements.size();
            if (freq >= k) {
                ans += indexesOfMaxElements[freq - k] + 1;
            }
        }

        return ans;
    }
};