class Solution {
public:
    string toLowerCase(string s) {
        string str;
        for(auto it : s){
            str += tolower(it);
        }
        return str;
    }
};