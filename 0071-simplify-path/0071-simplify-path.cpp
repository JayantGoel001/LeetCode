class Solution {
public:
    string simplifyPath(string path) {
        int i = 0;
        vector<string> st;
        while(i < path.size()) {
            string temp = "";
            while(i < path.size() && path[i] != '/') {
                temp.push_back(path[i++]);
            }
            if (temp != ".." && temp != "." && temp != "") st.push_back("/" + temp);
            if (temp == ".." && !st.empty()) st.pop_back();
            
            i++;
        }
        string res = "";
        for(auto it : st) {
            res += it;
        }

        return res == "" ? "/" : res;
    }
};