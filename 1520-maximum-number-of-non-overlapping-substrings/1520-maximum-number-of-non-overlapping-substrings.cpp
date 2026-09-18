class Solution {
public:
    struct Seg {
        int left, right;
        bool operator<(const Seg& rhs) const {
            if (right == rhs.right) {
                return left > rhs.left;
            }
            return right < rhs.right;
        }
    };

    vector<string> maxNumOfSubstrings(string s) {
        vector<Seg> seg(26, (Seg){-1, -1});
        // Preprocess the left and right endpoints.
        for (int i = 0; i < s.length(); ++i) {
            int charIdx = s[i] - 'a';
            if (seg[charIdx].left == -1) {
                seg[charIdx].left = seg[charIdx].right = i;
            } else {
                seg[charIdx].right = i;
            }
        }
        for (int i = 0; i < 26; ++i) {
            if (seg[i].left != -1) {
                for (int j = seg[i].left; j <= seg[i].right; ++j) {
                    int charIdx = s[j] - 'a';
                    if (seg[i].left <= seg[charIdx].left &&
                        seg[charIdx].right <= seg[i].right) {
                        continue;
                    }
                    seg[i].left = min(seg[i].left, seg[charIdx].left);
                    seg[i].right = max(seg[i].right, seg[charIdx].right);
                    j = seg[i].left;
                }
            }
        }
        // Greedily select intervals.
        sort(seg.begin(), seg.end());
        vector<string> ans;
        int end = -1;
        for (auto& segment : seg) {
            int left = segment.left, right = segment.right;
            if (left == -1) {
                continue;
            }
            if (end == -1 || left > end) {
                end = right;
                ans.emplace_back(s.substr(left, right - left + 1));
            }
        }
        return ans;
    }
};