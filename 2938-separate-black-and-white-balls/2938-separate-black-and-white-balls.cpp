class Solution {
public:
    long long minimumSteps(string s) {
        long long totalSwaps = 0;
        int blackBallCount = 0;

        // Iterate through each ball (character) in the string
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '0') {
                // Swap with all black balls to its left
                totalSwaps += (long long)blackBallCount;
            } else {
                // Increment the count
                blackBallCount++;
            }
        }

        return totalSwaps;
    }
};