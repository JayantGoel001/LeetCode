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
        for(int j=0;j<26;j++) {
            int mini = INT_MAX;
            
            for(int i=0;i<words.size();i++) {
                mini = min(mini, v[i][j]);
            }
            
            while(mini--) {
                string str(1, j + 'a');
                res.push_back(str);
            }
        }
        return res;
    }
};