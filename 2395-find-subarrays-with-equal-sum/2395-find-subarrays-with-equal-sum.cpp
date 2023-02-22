class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_set<int> st;
        
        for(int i=1;i<nums.size();i++){
            if(st.find(nums[i - 1] + nums[i]) != st.end()){
                return true;
            }
            st.insert(nums[i - 1] + nums[i]);
        }
        return false;
    }
};