class Solution {
public:
    vector<int> s;
    Solution(vector<int> w) {
        for (int i : w) s.push_back(s.empty() ? i : (i + s.back()));
    }
    
    int pickIndex() {
        int m = s.back();
        int r = rand() % m;
        auto it = upper_bound(s.begin(), s.end(), r);
        return it - s.begin();
    }
};