class Solution {
public:
    int maximumLength(string s) {
        // Create a map of strings to store the count of all substrings.
        map<pair<char, int>, int> count;
        int substringLength = 0;
        for (int start = 0; start < s.length(); start++) {
            char character = s[start];
            substringLength = 0;
            for (int end = start; end < s.length(); end++) {
                // If the string is empty, or the current character is equal to
                // the previously added character, then add it to the map.
                // Otherwise, break the iteration.
                if (character == s[end]) {
                    substringLength++;
                    count[{character, substringLength}]++;
                } else {
                    break;
                }
            }
        }

        // Create a variable ans to store the longest length of substring with
        // frequency atleast 3.
        int ans = 0;
        for (auto i : count) {
            int len = i.first.second;
            if (i.second >= 3 && len > ans) ans = len;
        }
        if (ans == 0) return -1;
        return ans;
    }
};