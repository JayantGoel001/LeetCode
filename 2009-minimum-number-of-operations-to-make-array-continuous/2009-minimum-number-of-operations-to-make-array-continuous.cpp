class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = n;
        
        // std::set automatically sorts
        set<int> unique(nums.begin(), nums.end());
        vector<int> newNums;
        for (int num : unique) {
            newNums.push_back(num);
        }
        
        int j = 0;
        for (int i = 0; i < newNums.size(); i++) {
            while (j < newNums.size() && newNums[j] < newNums[i] + n) {
                j++;
            }
            
            int count = j - i;
            ans = min(ans, n - count);
        }
        
        return ans;
    }
};