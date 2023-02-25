class Solution {
public:
    bool contains(string &word, unordered_set<char> &st){
        for(auto it : word){
            if(st.find(tolower(it)) == st.end()){
                return false;
            }
        }
        return true;
    }
    vector<string> findWords(vector<string>& words) {
        string str1 = "qwertyuiop";
        unordered_set<char> st1(str1.begin(), str1.end());
        string str2 = "asdfghjkl";
        unordered_set<char> st2(str2.begin(), str2.end());
        string str3 = "zxcvbnm";
        unordered_set<char> st3(str3.begin(), str3.end());
        
        vector<string> v;
        for(auto it : words){
            if(contains(it, st1) || contains(it, st2) || contains(it, st3)){
                v.push_back(it);
            }
        }
        return v;
    }
};