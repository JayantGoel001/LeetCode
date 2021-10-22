class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int size = nums.size();
        int ans = INT_MAX;
        
        int low = 0;
        int sum = 0;
        for(int i=0;i<size;i++){
            sum += nums[i];
            while(sum >= target){
                ans = min(ans,i - low + 1);
                sum -= nums[low++];
            }
        }
        return ans!=INT_MAX ? ans : 0;
    }
};