class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        for(int i = n;i > 1;i--){
            vector<int> v2;
            for(int j = 1;j<i;j++){
                v2.push_back((nums[j-1] + nums[j])%10);
            }
            nums = v2;
        }
        return nums[0];
    }
};