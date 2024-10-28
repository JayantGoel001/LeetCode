class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        // Map to store the length of square streak for each number
        unordered_map<int, int> streakLengths;

        sort(nums.begin(), nums.end());

        for (int number : nums) {
            int root = (int)sqrt(number);

            // Check if the number is a perfect square and its square root is in
            // the map
            if (root * root == number &&
                streakLengths.find(root) != streakLengths.end()) {
                // If so, extend the streak from its square root
                streakLengths[number] = streakLengths[root] + 1;
            } else {
                // Otherwise, start a new streak
                streakLengths[number] = 1;
            }
        }

        // Find the maximum streak length
        int longestStreak = 0;
        for (auto& [key, streakLength] : streakLengths) {
            longestStreak = max(longestStreak, streakLength);
        }

        // Return -1 if no valid streak found, otherwise return the longest
        // streak
        return longestStreak == 1 ? -1 : longestStreak;
    }
};