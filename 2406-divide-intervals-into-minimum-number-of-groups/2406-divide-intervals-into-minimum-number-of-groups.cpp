class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        // Find the minimum and maximum value in the interval
        int rangeStart = INT_MAX;
        int rangeEnd = INT_MIN;
        for (vector<int> interval : intervals) {
            rangeStart = min(rangeStart, interval[0]);
            rangeEnd = max(rangeEnd, interval[1]);
        }

        // Initialize the list with all zeroes
        vector<int> pointToCount(rangeEnd + 2, 0);
        for (vector<int> interval : intervals) {
            pointToCount[interval[0]]++;
            pointToCount[interval[1] + 1]--;
        }

        int concurrentIntervals = 0;
        int maxConcurrentIntervals = 0;
        for (int i = rangeStart; i <= rangeEnd; i++) {
            // Update currently active intervals
            concurrentIntervals += pointToCount[i];
            maxConcurrentIntervals =
                max(maxConcurrentIntervals, concurrentIntervals);
        }

        return maxConcurrentIntervals;
    }
};