class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        
        int dp[size+1];
        for(int i=0;i<=size;i++){
            dp[i] = 1;
        }
        for(int i=0;i<size;i++){
            for(int j=i+1;j<size;j++){
                if(nums[j] > nums[i]){
                    dp[j] = max(dp[j],dp[i] + 1);
                }
            }
        }
        int maxi = 0;
        for(auto it : dp){
            maxi = max(maxi,it);
        }
        return maxi;
    }
};