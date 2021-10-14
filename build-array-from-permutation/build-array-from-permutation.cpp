class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int size = nums.size();
        for(int i=0;i<size;i++){
            nums[i] = nums[i] + size * (nums[nums[i]]%size);
        }
        for(int i=0;i<size;i++){
            nums[i] = nums[i]/size;
        }
        return nums;
    }
};