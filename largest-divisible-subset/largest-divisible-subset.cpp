class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), maxIndex = 0, ans = INT_MIN;
        vector<int> dp(n, 1), parent(n, -1), sol;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if((nums[j] % nums[i] == 0 || nums[i] % nums[j] == 0) && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }
            if(dp[i] > ans) { //update ans and index of last element included when larger subset found
                ans = dp[i];
                maxIndex = i;
            }
        }
        while(maxIndex != -1) { //push the subset element one by one
            sol.push_back(nums[maxIndex]);
            maxIndex = parent[maxIndex];
        }
        return sol;
    }
};