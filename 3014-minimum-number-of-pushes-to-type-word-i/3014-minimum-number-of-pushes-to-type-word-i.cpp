class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int m = (n - 1) / 8 + 1;
        return m * (m - 1) * 4 + (n - (m - 1) * 8) * m;
    }
};