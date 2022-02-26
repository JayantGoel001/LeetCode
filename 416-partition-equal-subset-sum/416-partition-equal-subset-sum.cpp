class Solution {
public:
    vector<vector<int>> dp;
    
    bool isEqual(vector<int>& nums,int sum,int i){
        if(sum == 0 && i == nums.size()){
            return true;
        }
        if(i == nums.size() || sum < 0){
            return false;
        }
        if(dp[i][sum] == -1){
            dp[i][sum] = isEqual(nums,sum - nums[i],i + 1) || isEqual(nums,sum,i + 1);
        }
        return dp[i][sum];
    }
    
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(auto it : nums){
            sum += it;
        }
        dp.resize(n,vector<int> (sum/2 + 1, -1));
        
        if(sum%2 == 0){
            return isEqual(nums,sum/2,0);
        }else{
            return false;
        }
    }
};