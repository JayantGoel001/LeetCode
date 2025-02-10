class Solution {
public:
    string clearDigits(string s) {
        string answer;

        // Iterate over each character in the input string
        for (int charIndex = 0; charIndex < s.size(); charIndex++) {
            // If the current character is a digit
            if (isdigit(s[charIndex]) && !answer.empty()) {
                // If the answer string is not empty, remove the last character
                answer.pop_back();
            } else {
                // If the character is not a digit, add it to the answer string
                answer += s[charIndex];
            }
        }

        return answer;
    }
};