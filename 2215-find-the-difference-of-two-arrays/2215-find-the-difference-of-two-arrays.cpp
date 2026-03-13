class Solution {
public:
    vector<int> findDiff(unordered_set<int> &st1, unordered_set<int> &st2) {
        vector<int> v;
        for(auto it : st1) {
            if (st2.find(it) == st2.end()) {
                v.push_back(it);
            }
        }

        return v;
    }
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st1, st2;

        for(auto it : nums1) st1.insert(it);
        for(auto it : nums2) st2.insert(it);

        vector<vector<int>> res;

        res.push_back(findDiff(st1, st2));
        res.push_back(findDiff(st2, st1));

        return res;
    }
};