class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters,
                                 vector<int>& queryIndices) {
        int n = s.size();
        set<pair<int, int>> segs;
        multiset<int> lens;

        for (int i = 0; i < n;) {
            int j = i;
            while (j < n && s[j] == s[i]) {
                j++;
            }
            segs.insert({i, j - 1});
            lens.insert(j - i);
            i = j;
        }

        int k = queryIndices.size();
        vector<int> ans(k);

        for (int q = 0; q < k; q++) {
            int pos = queryIndices[q];
            char ch = queryCharacters[q];

            if (s[pos] != ch) {
                auto it = segs.upper_bound({pos, INT_MAX});
                --it;
                int L = it->first, R = it->second;
                segs.erase(it);
                lens.erase(lens.find(R - L + 1));

                if (L <= pos - 1) {
                    segs.insert({L, pos - 1});
                    lens.insert(pos - L);
                }
                if (pos + 1 <= R) {
                    segs.insert({pos + 1, R});
                    lens.insert(R - pos);
                }

                int newL = pos, newR = pos;

                auto rightIt = segs.lower_bound({pos + 1, 0});
                if (rightIt != segs.end() && rightIt->first == pos + 1 &&
                    s[pos + 1] == ch) {
                    lens.erase(lens.find(rightIt->second - rightIt->first + 1));
                    newR = rightIt->second;
                    segs.erase(rightIt);
                }

                auto leftIt = segs.lower_bound({pos, 0});
                if (leftIt != segs.begin()) {
                    --leftIt;
                    if (leftIt->second == pos - 1 && s[pos - 1] == ch) {
                        lens.erase(
                            lens.find(leftIt->second - leftIt->first + 1));
                        newL = leftIt->first;
                        segs.erase(leftIt);
                    }
                }

                segs.insert({newL, newR});
                lens.insert(newR - newL + 1);
                s[pos] = ch;
            }

            ans[q] = *lens.rbegin();
        }

        return ans;
    }
};