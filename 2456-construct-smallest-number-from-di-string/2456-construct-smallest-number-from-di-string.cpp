class Solution {
public:
    string smallestNumber(string pattern) {
        int patternLength = pattern.length();
        int maxSoFar = 0, currMax = 0, temp;

        // Array to store lengths of decreasing subsequences in the pattern
        vector<int> arrD(patternLength + 1, 0);

        // Compute the lengths of decreasing subsequences in the pattern
        for (int patternIndex = patternLength - 1; patternIndex >= 0;
             patternIndex--) {
            if (pattern[patternIndex] == 'D')
                // If 'D', increment the length of the decreasing sequence
                arrD[patternIndex] = arrD[patternIndex + 1] + 1;
        }

        string result = "";

        // Build the result string based on the pattern
        for (int position = 0; position <= patternLength; position++) {
            if (pattern[position] == 'I') {
                // If 'I', assign the next maximum digit and append it to the
                // result
                maxSoFar++;
                result += '0' + maxSoFar;

                // Update the max digit encountered so far
                maxSoFar = max(maxSoFar, currMax);

                // Reset current max for the next iteration
                currMax = 0;
            } else {
                // If 'D', calculate the appropriate digit and append it to the
                // result
                temp = 1 + maxSoFar + arrD[position];
                result += '0' + temp;

                // Update the current max value
                currMax = max(currMax, temp);
            }
        }

        return result;
    }
};