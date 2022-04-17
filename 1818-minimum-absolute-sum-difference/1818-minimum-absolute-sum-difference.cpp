class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& n1, vector<int>& n2) {
        long res = 0, gain = 0;
        set<int> s(begin(n1), end(n1));
        for (int i = 0; i < n1.size(); ++i) {
            long original = abs(n1[i] - n2[i]);
            res += original;
            if (gain < original) {
                auto it = s.lower_bound(n2[i]);
                if (it != end(s))
                    gain = max(gain, original - abs(*it - n2[i]));
                if (it != begin(s))
                    gain = max(gain, original - abs(*prev(it) - n2[i]));
            }
        }
        return (res - gain) % 1000000007;
    }
};