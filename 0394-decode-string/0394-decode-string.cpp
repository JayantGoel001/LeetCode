#define psi pair<string, int>
class Solution {
public:
    string getString(string &s, int num) {
        string res = "";
        while(num--) {
            res += s;
        }
        return res;
    }
    string decodeString(string s) {
        string curr = "";
        
        stack<psi> st;
        int i = 0;
        while(i < s.size()) {
            int num = 0;
            while (i < s.size() && s[i] >= '0' && s[i] <= '9') {
                num = num * 10 + (s[i] - '0');
                i++;
            }
            if (s[i] == '[') {
                st.push({curr, num});
                curr = "";
            } else if (s[i] == ']') {
                psi top = st.top();
                st.pop();
                curr = top.first + getString(curr, top.second);
            } else {
                curr.push_back(s[i]);
            }
            i++;
        }
        return curr;
    }
};