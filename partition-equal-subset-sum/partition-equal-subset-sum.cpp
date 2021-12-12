class Solution {
public:
    int dp[201][20001];
    bool getPoss(vector<int> &nums,int i,int target){
        if(i == nums.size() && target == 0){
            return true;
        }
        if(i==nums.size() || target<0){
            return false;
        }
        
        if(dp[i][target] != -1){
            return dp[i][target];
        }
        dp[i][target] = getPoss(nums,i+1,target - nums[i]) || getPoss(nums,i+1,target);
        return dp[i][target];
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto it : nums){
            sum += it;
        }
        memset(dp,-1,sizeof dp);
        if(sum%2==0){
            return getPoss(nums,0,sum/2);
        }else{
            return false;
        }
    }
};