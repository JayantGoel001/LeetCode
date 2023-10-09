class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v(2,-1);
        
        int pos1 = lower_bound(nums.begin(),nums.end(),target) - nums.begin();
        int size = nums.size();
        
        if(pos1 != size && nums[pos1] == target){
            v[0] = pos1;
        }
        int pos2 = upper_bound(nums.begin(),nums.end(),target) - nums.begin();
        if(pos2 !=0){
            pos2-=1;
            
            if(pos2 != size && nums[pos2] == target){
                v[1] = pos2;
            }
        }
        return v;
    }
};