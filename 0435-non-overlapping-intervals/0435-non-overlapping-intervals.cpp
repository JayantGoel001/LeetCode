class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int count = 0;
        int prev = INT_MIN;
        for(auto it : intervals) {
            if (prev == INT_MIN || prev <= it[0]) {
                count++;
                prev = it[1];
            } else {
                prev = min(prev, it[1]);
            }
        }

        return intervals.size() - count;
    }
};