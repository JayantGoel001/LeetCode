class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(auto it : nums){
            if(nums[abs(it)] < 0){
                return abs(it);
            }else{
                nums[abs(it)] = -nums[abs(it)];
            }
        }
        return -1;
    }
};