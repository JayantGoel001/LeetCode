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
            while(k < nums.size() && nums[k] == 0){
                k++;
            }
            if(k < nums.size()){
                nums[i] = nums[k++];
            }
        }
        
        for(int i=0;i<zero;i++){
            nums[nums.size() - i - 1] = 0;
        }
        return nums;
    }
};