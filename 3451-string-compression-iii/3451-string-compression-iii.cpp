class Solution {
public:
    string compressedString(string word) {
        string comp = "";

        // pos tracks our position in the input string
        int pos = 0;

        // Process until we reach end of string
        while (pos < word.length()) {
            int consecutiveCount = 0;

            char currentChar = word[pos];

            // Count consecutive occurrences (maximum 9)
            while (pos < word.length() && consecutiveCount < 9 &&
                   word[pos] == currentChar) {
                consecutiveCount++;
                pos++;
            }

            // Append count followed by character to result
            comp += to_string(consecutiveCount) + currentChar;
        }

        return comp;
    }
};