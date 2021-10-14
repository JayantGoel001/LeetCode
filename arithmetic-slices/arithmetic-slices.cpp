class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int size = nums.size();
        
        if(size < 3){
            return 0;
        }
        
        int dp[size + 1];
        for(int i=0;i<=size;i++){
            dp[i] = 0;
        }
        int ans = 0;
        for(int i=2;i<size;i++){
            if(nums[i] - nums[i-1] == nums[i-1] - nums[i-2]){
                dp[i] = dp[i-1] + 1;
                ans += dp[i];
            }
        }
        return ans;
    }
};