class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string result;
        // Pre-allocate space for efficiency
        result.reserve(s.size() + spaces.size());

        int spaceIndex = 0;
        for (int stringIndex = 0; stringIndex < s.size(); ++stringIndex) {
            if (spaceIndex < spaces.size() &&
                stringIndex == spaces[spaceIndex]) {
                // Insert space at the correct position
                result += ' ';
                ++spaceIndex;
            }
            // Append the current character
            result += s[stringIndex];
        }

        return result;
    }
};