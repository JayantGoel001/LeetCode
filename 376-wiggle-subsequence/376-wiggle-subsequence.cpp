class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() <= 1){
            return nums.size();
        }
        int prev = nums[1] - nums[0];
        int maxi = prev == 0 ? 1 : 2;
        
        for(int i=1;i<nums.size()-1;i++){
            int diff = nums[i + 1] - nums[i];
            if((diff > 0 && prev <= 0) || (diff < 0 && prev >= 0)){
                maxi++;
                prev = diff;
            }
        }
        return maxi;
    }
};