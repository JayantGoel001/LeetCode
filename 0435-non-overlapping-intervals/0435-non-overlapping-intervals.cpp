class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int count = 0;
        vector<int> last;
        for(auto it : intervals) {
            if (last.empty() || last[1] <= it[0]) {
                count++;
                last = it;
            } else {
                last[1] = min(last[1], it[1]);
            }
        }

        return intervals.size() - count;
    }
};