class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> cnt(26);
        for (int i = 0; i < s.size(); i++) {
            cnt[s[i] - 'a']++;
            cnt[target[i] - 'a']--;
        }

        // Try from right to left
        for (int i = s.size() - 1; i >= 0; i--) {
            int b = target[i] - 'a';
            cnt[b]++;  // Reversal of consumption
                       // Check if the prefix can fully match
            if (*min_element(cnt.begin(), cnt.end()) < 0) {
                continue;
            }
            // Find the smallest available character larger than b.
            for (int j = b + 1; j < 26; j++) {
                if (cnt[j]) {
                    cnt[j]--;
                    target[i] = 'a' + j;
                    target.resize(i + 1);
                    return target + getMinString(cnt);
                }
            }
        }

        return "";
    }

    // Get the lexicographically smallest string (in ascending order)
    string getMinString(const vector<int>& cnt) {
        string res;
        for (int i = 0; i < 26; i++) {
            res.append(cnt[i], 'a' + i);
        }
        return res;
    }
};