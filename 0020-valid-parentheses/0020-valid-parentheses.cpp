class Solution {
public:
    bool isValid(string &s) {
        unordered_map<char,char> mp;
        mp['('] = ')';
        mp['{'] = '}';
        mp['['] = ']';

        stack<char> st;
        for(auto it : s) {
            if (mp.find(it) != mp.end()) {
                st.push(it);
            } else {
                if (st.empty() || mp[st.top()] != it) return false;
                st.pop();
            }
        }
        return st.empty();
    }
};