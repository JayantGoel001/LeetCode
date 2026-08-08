class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length(), m = word2.length();
        vector<int> last(m, -1);
        int j = m - 1;
        for (int i = n - 1; i >= 0; --i) {
            if (j >= 0 && word1[i] == word2[j]) {
                last[j] = i;
                j -= 1;
            }
        }
        vector<int> res;
        int skip = 0;
        j = 0;
        for (int i = 0; i < n; ++i) {
            if (j == m) break;
            if (word1[i] == word2[j] ||
                (skip == 0 && (j == m - 1 || i < last[j + 1]))) {
                skip += (word1[i] != word2[j] ? 1 : 0);
                res.push_back(i);
                j += 1;
            }
        }
        return j == m ? res : vector<int>();
    }
};