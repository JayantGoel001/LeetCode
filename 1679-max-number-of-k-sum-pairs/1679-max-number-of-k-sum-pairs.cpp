class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> seen;
        int ans = 0;
        for (int b : nums) {
            int a = k - b;
            if (seen[a] > 0) {
                ans += 1;
                seen[a] -= 1;
            } else {
                seen[b] += 1;
            }
        }
        return ans;
    }
};