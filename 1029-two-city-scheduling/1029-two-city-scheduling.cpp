class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& cs, int res = 0) {
        nth_element(begin(cs), begin(cs) + cs.size() / 2, end(cs), [](vector<int> &a, vector<int> &b) {
            return (a[0] - a[1] < b[0] - b[1]);
        });
        for (auto i = 0; i < cs.size() / 2; ++i) {
            res += cs[i][0] + cs[i + cs.size() / 2][1];
        }
        return res;
    }
};