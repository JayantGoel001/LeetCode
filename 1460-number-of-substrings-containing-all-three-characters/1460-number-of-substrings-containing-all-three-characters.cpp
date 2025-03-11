class Solution {
public:
    int numberOfSubstrings(string s) {
        int len = s.length();
        // Track last position of a, b, c
        vector<int> lastPos = {-1, -1, -1};
        int total = 0;

        for (int pos = 0; pos < len; pos++) {
            // Update last position of current character
            lastPos[s[pos] - 'a'] = pos;

            // Add count of valid substrings ending at current position
            // If any character is missing, min will be -1
            // Else min gives leftmost required character position
            total += 1 + min({lastPos[0], lastPos[1], lastPos[2]});
        }

        return total;
    }
};