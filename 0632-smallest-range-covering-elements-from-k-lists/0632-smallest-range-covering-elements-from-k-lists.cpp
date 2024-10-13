class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int, int>> merged;

        // Merge all lists with their list index
        for (int i = 0; i < nums.size(); i++) {
            for (int num : nums[i]) {
                merged.push_back({num, i});
            }
        }

        // Sort the merged list
        sort(merged.begin(), merged.end());

        // Two pointers to track the smallest range
        unordered_map<int, int> freq;
        int left = 0, count = 0;
        int rangeStart = 0, rangeEnd = INT_MAX;

        for (int right = 0; right < merged.size(); right++) {
            freq[merged[right].second]++;
            if (freq[merged[right].second] == 1) count++;

            // When all lists are represented, try to shrink the window
            while (count == nums.size()) {
                int curRange = merged[right].first - merged[left].first;
                if (curRange < rangeEnd - rangeStart) {
                    rangeStart = merged[left].first;
                    rangeEnd = merged[right].first;
                }

                freq[merged[left].second]--;
                if (freq[merged[left].second] == 0) count--;
                left++;
            }
        }

        return {rangeStart, rangeEnd};
    }
};