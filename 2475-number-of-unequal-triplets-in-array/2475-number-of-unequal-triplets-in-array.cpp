class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        int count = 0;
        for(int i=0;i<nums.size();i++){
            for(int j = i + 1; j < nums.size(); j++){
                if(nums[i] != nums[j]){
                    for(int k = j + 1; k < nums.size(); k++){
                        count += (nums[i] != nums[k] && nums[j] != nums[k]);
                    }
                }
            }
        }
        return count;
    }
};