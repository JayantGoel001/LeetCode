class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(nums[i] != 0){
                nums[i] += i==0?0:nums[i-1];
            }
        }
        int maxi = 0;
        for(auto it : nums){
            maxi = max(maxi,it);
        }
        return maxi;
    }
};