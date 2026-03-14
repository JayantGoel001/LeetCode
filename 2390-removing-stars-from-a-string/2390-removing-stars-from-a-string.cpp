class Solution {
public:
    string removeStars(string s) {
        vector<char> v;
        for(auto it : s) {
            if (it == '*') {
                v.pop_back();
            } else {
                v.push_back(it);
            }
        }

        string str = "";
        for(auto it : v) {
            str.push_back(it);
        }

        return str;
    }
};