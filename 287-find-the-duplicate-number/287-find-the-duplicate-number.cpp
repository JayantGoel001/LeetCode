class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            int cur = abs(nums[i]) - 1;
            if(nums[cur] < 0){
                return cur + 1;
            }
            nums[cur] *= -1;
        }
        return -1;
    }
};