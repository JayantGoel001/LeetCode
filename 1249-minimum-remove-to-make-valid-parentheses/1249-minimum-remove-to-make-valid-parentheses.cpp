class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        for (auto i = 0; i < s.size(); ++i) {
            if (s[i] == '('){
                st.push(i);
            }
            if (s[i] == ')') {
              if (!st.empty()){
                  st.pop();
              } else {
                  s[i] = '*';
              }
            }
        }
        while (!st.empty()) {
            s[st.top()] = '*';
            st.pop();
        }
        s.erase(remove(s.begin(), s.end(), '*'), s.end());
        return s;
    }
};