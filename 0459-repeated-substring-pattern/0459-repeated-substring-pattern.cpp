class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string t = s + s;
        return t.substr(1, t.size() - 2).find(s) != -1;
    }
};