class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        for(int i=1;i<nums.size();i++){
            if(nums[i - 1] == nums[i]){
                nums[i - 1] = 2 * nums[i - 1];
                nums[i] = 0;
                i++;
            }
        }
        int zero = 0;
        for(auto it : nums){
            zero += it == 0;
        }
        
        int k = 0;
        for(int i=0;i<nums.size();i++){
            nums[k] = nums[i];
            if(nums[i] != 0){
                k++;
            }
        }
        
        while(k < nums.size()){
            nums[k++] = 0;
        }
        return nums;
    }
};