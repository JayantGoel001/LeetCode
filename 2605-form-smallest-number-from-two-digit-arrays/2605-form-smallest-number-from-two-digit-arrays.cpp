class Solution {
public:
    int getMin(vector<int> &nums){
        int mini = nums[0];
        for(auto it : nums){
            mini = min(mini, it);
        }
        return mini;
    }
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        vector<bool> mp(10, false);
        for(auto it : nums2){
            mp[it] = true;
        }
        int res = INT_MAX;
        for(auto it : nums1){
            if(mp[it]){
                res = min(res, it);
            }
        }
        if(res != INT_MAX){
            return res;
        }
        int min1 = getMin(nums1);
        int min2 = getMin(nums2);
        
        return min(min1, min2) * 10 + max(min1, min2);
    }
};