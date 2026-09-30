class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> ans;
        for (int i = 0; i < (int)seq.size(); ++i) {
            ans.push_back(i & 1 ^ (seq[i] == '('));
        }
        return ans;
    }
};