class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++) {
            if (i != 0) nums[i] += nums[i - 1];
            
            nums[i] = (k + nums[i] % k) % k;
        }
        
        vector<int> v(k, 0);
        v[0] = 1;
        
        int count = 0;
        for(auto it : nums) {
            count += v[it]++;
        }
        
        return count;
    }
};