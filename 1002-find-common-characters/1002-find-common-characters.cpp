class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<vector<int>> v(words.size(), vector<int>(26, 0));
        
        for(int i=0;i<words.size();i++){
            for(auto ch: words[i]) {
                v[i][ch - 'a']++;
            }
        }
        
        vector<string> res;
        for(int i=0;i<26;i++) {
            int mini = INT_MAX;
            
            for(int j=0;j<words.size();j++) {
                mini = min(mini, v[j][i]);
            }
            
            while(mini--) {
                string str(1, i + 'a');
                res.push_back(str);
            }
        }
        return res;
    }
};