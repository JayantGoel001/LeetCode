class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size()-2;
        while(i>=0 && nums[i] >= nums[i+1]){
            i--;
        }
        if(i>=0){
            int k = nums.size()-1;
            while(nums[k] <= nums[i]){
                k--;
            }
            swap(nums[k],nums[i]);
        }
        reverse(nums.begin()+i+1,nums.end());
        
    }
};