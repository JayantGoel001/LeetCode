class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long badPairs = 0;
        unordered_map<int, int> diffCount;

        for (int pos = 0; pos < nums.size(); pos++) {
            int diff = pos - nums[pos];

            // Count of previous positions with same difference
            int goodPairsCount = diffCount[diff];

            // Total possible pairs minus good pairs = bad pairs
            badPairs += pos - goodPairsCount;

            // Update count of positions with this difference
            diffCount[diff] = goodPairsCount + 1;
        }

        return badPairs;
    }
};