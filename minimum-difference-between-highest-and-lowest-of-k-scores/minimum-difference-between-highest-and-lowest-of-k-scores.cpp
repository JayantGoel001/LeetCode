class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end()); 
        int n = nums.size();
        
        int diff = nums[k - 1] - nums[0];
        for(int i=k;i<n;i++){
            diff = min(diff,nums[i] - nums[i - k + 1]);
        }
        
        return diff;
    }
};