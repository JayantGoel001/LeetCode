class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;
        for(int i = 0; i < words.size(); ++i){
            for(auto c: words[i]) {
                if(c == x) { ans.push_back(i); break; }
            }
        }
        return ans;
    }
};