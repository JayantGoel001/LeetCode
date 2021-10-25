class Solution {
public:
    int getNOPC(vector<int>& nums, int target,int *dp){
        if(target == 0){
            return 1;
        }else if(target > 0){
            if(dp[target]!=-1){
                return dp[target];
            }
            dp[target] = 0;
            int size = nums.size();
            for(int i=0;i<size;i++){
                dp[target] += getNOPC(nums,target - nums[i],dp);
            }
            return dp[target];
            
        }else{
            return 0;
        }
        
    }
    int combinationSum4(vector<int>& nums, int target) {
        int dp[target + 1];
        
        for(int i=0;i<=target;i++){
            dp[i] = -1;
        }
        getNOPC(nums,target,dp);
        return dp[target];
    }
};