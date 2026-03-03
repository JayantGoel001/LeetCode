class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> res;
        for(auto it : intervals) {
            if (res.empty() || res.back()[1] < it[0]) {
                res.push_back(it);
            } else {
                res.back()[1] = max(res.back()[1], it[1]);
            }
        }

        return res;
    }
};