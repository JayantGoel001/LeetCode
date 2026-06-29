class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        auto check = [](const string& pattern, const string& word) -> bool {
            int m = pattern.size();
            int n = word.size();
            // generate the prefix array of the pattern
            vector<int> pi(m);
            for (int i = 1, j = 0; i < m; i++) {
                while (j > 0 && pattern[i] != pattern[j]) {
                    j = pi[j - 1];
                }
                if (pattern[i] == pattern[j]) {
                    ++j;
                }
                pi[i] = j;
            }
            // using prefix arrays for matching
            for (int i = 0, j = 0; i < n; i++) {
                while (j > 0 && word[i] != pattern[j]) {
                    j = pi[j - 1];
                }
                if (word[i] == pattern[j]) {
                    ++j;
                }
                if (j == m) {
                    return true;
                }
            }
            return false;
        };

        int res = 0;
        for (const string& pattern : patterns) {
            res += check(pattern, word);
        }
        return res;
    }
};