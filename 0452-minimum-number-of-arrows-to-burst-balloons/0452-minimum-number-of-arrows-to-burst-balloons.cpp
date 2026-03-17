class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        vector<int> last;
        int count = 0;
        for(auto it : points) {
            if (last.empty() || last[1] < it[0]) {
                count++;
                last = it;
            } else {
                last[1] = min(last[1], it[1]);
            }
        }
        return count;
    }
};