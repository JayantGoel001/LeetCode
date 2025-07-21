class Solution {
public:
    string makeFancyString(string s) {
        // If size of string is less than 3, return it.
        if (s.length() < 3) {
            return s;
        }
        int j = 2;
        for (int i = 2; i < s.size(); ++i) {
            // If the current character is not equal to the previously inserted
            // two characters, then we can add it to the string.
            if (s[i] != s[j - 1] || s[i] != s[j - 2]) {
                s[j++] = s[i];
            }
        }

        // Resize the string to the number of characters added in the string,
        // given by j.
        s.resize(j);
        return s;
    }
};