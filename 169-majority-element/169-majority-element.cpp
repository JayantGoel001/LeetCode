class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int can = 0;
        int count = 0;
        for(int i=0;i<nums.size();i++){
            if(count == 0){
                can = nums[i];
            }
            count += can == nums[i] ? 1 : -1;
        }
        return can;
    }
};