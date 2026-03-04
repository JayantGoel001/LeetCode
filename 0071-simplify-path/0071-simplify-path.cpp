class Solution {
public:
    string simplifyPath(string path) {
        int i = 0;
        stack<string> st;
        while(i < path.size()) {
            string temp = "";
            while(i < path.size() && path[i] != '/') {
                temp.push_back(path[i++]);
            }
            
            if (temp == "..") {
              if (!st.empty()) st.pop();
            } else if (temp != "." && temp != "") st.push("/" + temp);
            
            i++;
        }
        string res = "";
        while(!st.empty()) {
            res = st.top() + res;
            st.pop();
        }

        return res == "" ? "/" : res;
    }
};