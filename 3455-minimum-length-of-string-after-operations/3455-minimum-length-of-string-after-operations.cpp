class Solution {
public:
    int minimumLength(string s) {
        // Step 1: Initialize a frequency array to count occurrences of each
        // character
        vector<int> charFrequency(26, 0);
        int totalLength = 0;

        // Step 2: Count the frequency of each character in the string
        for (char currentChar : s) {
            charFrequency[currentChar - 'a']++;
        }

        // Step 3: Calculate the total length after deletions count
        for (int frequency : charFrequency) {
            if (frequency == 0) continue;  // Skip characters that don't appear
            if (frequency % 2 == 0) {
                totalLength += 2;  // If frequency is even, add 2
            } else {
                totalLength += 1;  // If frequency is odd, add 1
            }
        }

        // Step 4: Return the minimum length after deletions count
        return totalLength;
    }
};