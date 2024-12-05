class Solution {
public:
    bool canChange(string start, string target) {
        int startLength = start.size();
        // Pointer for start string and target string
        int startIndex = 0, targetIndex = 0;

        while (startIndex < startLength || targetIndex < startLength) {
            // Skip underscores in start
            while (startIndex < startLength && start[startIndex] == '_') {
                startIndex++;
            }
            // Skip underscores in target
            while (targetIndex < startLength && target[targetIndex] == '_') {
                targetIndex++;
            }
            // If one string is exhausted, both should be exhausted
            if (startIndex == startLength || targetIndex == startLength) {
                return startIndex == startLength && targetIndex == startLength;
            }

            // Check if the pieces match and follow movement rules
            if (start[startIndex] != target[targetIndex] ||
                (start[startIndex] == 'L' && startIndex < targetIndex) ||
                (start[startIndex] == 'R' && startIndex > targetIndex))
                return false;

            startIndex++;
            targetIndex++;
        }

        // If all conditions are satisfied, return true
        return true;
    }
};