class Solution {
public:
    bool similar(string &s, unordered_set<char> &st){
        for(auto it : s){
            if(st.find(it) == st.end()){
                return false;
            }
        }
        return true;
    }
    int similarPairs(vector<string>& words) {
        int count = 0;
        vector<unordered_set<char>> v;
        for(auto it : words){
            v.push_back(unordered_set<char> (it.begin(), it.end()));
        }
        for(int i=0;i<words.size();i++){
            for(int j=i + 1;j < words.size();j++){
                count += similar(words[i], v[j]) && similar(words[j], v[i]);
            }
        }
        return count;
    }
};