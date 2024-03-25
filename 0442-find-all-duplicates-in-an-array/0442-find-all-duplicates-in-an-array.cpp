class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> v;
        for(auto it:nums){
            it = abs(it);
            if(nums[it-1] < 0){
                v.push_back(it);
            }else{
                nums[it-1] = -nums[it-1];
            }
        }
        
        return v;
    }
};