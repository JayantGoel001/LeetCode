class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        // Store banned numbers in an unordered_set
        unordered_set<int> bannedSet(banned.begin(), banned.end());

        int count = 0;

        // Try each number from 1 to n
        for (int num = 1; num <= n; num++) {
            // Skip banned numbers
            if (bannedSet.count(num)) continue;

            // Return if adding current number exceeds maxSum
            if (maxSum - num < 0) return count;

            // Include current number
            maxSum -= num;
            count++;
        }
        return count;
    }
};