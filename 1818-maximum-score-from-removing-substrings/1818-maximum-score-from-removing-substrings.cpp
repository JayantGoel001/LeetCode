class Solution {
public:
    int maximumGain(string s, int x, int y) {
        // Ensure "ab" always has more points than "ba"
        if (x < y) {
            // Swap points
            int temp = x;
            x = y;
            y = temp;
            // Reverse the string to maintain logic
            reverse(s.begin(), s.end());
        }

        int aCount = 0, bCount = 0, totalPoints = 0;

        for (int i = 0; i < s.size(); ++i) {
            char currentChar = s[i];

            if (currentChar == 'a') {
                ++aCount;
            } else if (currentChar == 'b') {
                if (aCount > 0) {
                    // Can form "ab", remove it and add points
                    --aCount;
                    totalPoints += x;
                } else {
                    // Can't form "ab", keep 'b' for potential future "ba"
                    ++bCount;
                }
            } else {
                // Non 'a' or 'b' character encountered
                // Calculate points for any remaining "ba" pairs
                totalPoints += min(bCount, aCount) * y;
                // Reset counters for next segment
                aCount = bCount = 0;
            }
        }
        // Calculate points for any remaining "ba" pairs at the end
        totalPoints += min(bCount, aCount) * y;

        return totalPoints;
    }
};