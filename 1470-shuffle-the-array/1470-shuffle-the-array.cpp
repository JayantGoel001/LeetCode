class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int k = 1001;
        for(int i=0;i<nums.size();i++){
            nums[i] = k * nums[i];
        }
        for(int i = 0; i < nums.size(); i += 2){
            nums[i] += nums[i/2]/k;
            nums[i + 1] += nums[i/2 + n]/k; 
        }
        for(int i = 0;i < nums.size(); i++){
            nums[i] = nums[i] % k;
        }
        return nums;
    }
};