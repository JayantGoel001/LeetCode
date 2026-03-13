class Solution {
public:
    vector<int> findDiff(vector<int>& nums, unordered_set<int> &st) {
        vector<int> v;
        for(auto it : nums) {
            if (st.find(it) == st.end()) {
                v.push_back(it);
                st.insert(it);
            }
        }

        return v;
    }
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st1, st2;

        for(auto it : nums1) st1.insert(it);
        for(auto it : nums2) st2.insert(it);

        vector<vector<int>> res;

        res.push_back(findDiff(nums1, st2));
        res.push_back(findDiff(nums2, st1));

        return res;
    }
};