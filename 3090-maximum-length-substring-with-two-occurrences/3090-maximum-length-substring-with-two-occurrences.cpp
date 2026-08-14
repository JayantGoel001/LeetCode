class Solution {
public:
    int maximumLengthSubstring(string s) {
        array<int, 26> count{};
        int left = 0;
        int res = 0;
        for (int right = 0; right < s.length(); ++right) {
            int ch = s[right] - 'a';
            ++count[ch];
            while (count[ch] > 2) {
                const int ch2 = s[left] - 'a';
                --count[ch2];
                ++left;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};