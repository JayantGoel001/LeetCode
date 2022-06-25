class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool found = false;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i] > nums[i + 1]){
                if(found){
                    return false;
                }
                if(i < 1 || nums[i - 1] <= nums[i + 1]){
                    nums[i] = nums[i + 1];
                }else{
                    nums[i + 1] = nums[i];
                }
                found = true;
            }
        }
        return true;
    }
};
