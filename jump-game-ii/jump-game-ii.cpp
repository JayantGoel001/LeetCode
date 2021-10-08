class Solution {
public:
    int jump(vector<int>& nums) {
        int size = nums.size();
        int dp[size];
        
        for(int i=0;i<size;i++){
            dp[i] = INT_MAX;
        }
        dp[0] = 0;
        for(int i = 0;i<size;i++){
            for(int j = 0;j<=nums[i];j++){
                if(i + j < size){
                    dp[i + j] = min(dp[i + j],dp[i] + 1);
                }
            }
        }
        return dp[size-1];
    }
};