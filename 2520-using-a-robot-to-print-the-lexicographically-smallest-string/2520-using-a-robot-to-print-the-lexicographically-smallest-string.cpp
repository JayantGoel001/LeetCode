class Solution {
public:
    string robotWithString(string s) {
        unordered_map<char, int> cnt;
        for (char c : s) {
            cnt[c]++;
        }

        stack<char> stk;
        string res;
        char minCharacter = 'a';
        for (char c : s) {
            stk.emplace(c);
            cnt[c]--;
            while (minCharacter != 'z' && cnt[minCharacter] == 0) {
                minCharacter++;
            }
            while (!stk.empty() && stk.top() <= minCharacter) {
                res.push_back(stk.top());
                stk.pop();
            }
        }

        return res;
    }
};