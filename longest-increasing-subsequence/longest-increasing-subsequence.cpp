class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        int dp[size+1];
        
        for(int i=0;i<=size;i++){
            dp[i] = 1;
        }
        for(int i=0;i<size;i++){
            for(int j=i;j>=0;j--){
                if(nums[j] < nums[i]){
                    dp[i] = max(dp[i],dp[j] + 1);
                }
            }
        }
        int maxi = 0;
        for(int i=0;i<=size;i++){
            maxi = max(maxi,dp[i]);
        }
        return maxi;
    }
};