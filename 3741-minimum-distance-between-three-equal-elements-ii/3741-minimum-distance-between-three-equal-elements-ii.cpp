class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        std::vector<int> next(n, -1);
        std::unordered_map<int, int> occur;
        int ans = n + 1;

        for (int i = n - 1; i >= 0; i--) {
            if (occur.count(nums[i])) {
                next[i] = occur[nums[i]];
            }
            occur[nums[i]] = i;
        }

        for (int i = 0; i < n; i++) {
            int secondPos = next[i];
            if (secondPos != -1) {
                int thirdPos = next[secondPos];
                if (thirdPos != -1) {
                    ans = std::min(ans, thirdPos - i);
                }
            }
        }

        return ans == n + 1 ? -1 : ans * 2;
    }
};