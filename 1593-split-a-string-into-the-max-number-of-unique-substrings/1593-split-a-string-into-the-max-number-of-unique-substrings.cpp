class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> seen;
        return backtrack(s, 0, seen);
    }

private:
    int backtrack(const string& s, int start, unordered_set<string>& seen) {
        // Base case: If we reach the end of the string, return 0 (no more
        // substrings to add)
        if (start == s.size()) return 0;

        int maxCount = 0;

        // Try every possible substring starting from 'start'
        for (int end = start + 1; end <= s.size(); ++end) {
            string substring = s.substr(start, end - start);
            // If the substring is unique
            if (seen.find(substring) == seen.end()) {
                // Add the substring to the seen set
                seen.insert(substring);
                // Recursively count unique substrings from the next position
                maxCount = max(maxCount, 1 + backtrack(s, end, seen));
                // Backtrack: remove the substring from the seen set
                seen.erase(substring);
            }
        }
        return maxCount;
    }
};