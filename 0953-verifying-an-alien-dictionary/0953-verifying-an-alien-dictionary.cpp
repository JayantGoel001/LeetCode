class Solution {
public:
    bool isAlienSorted(vector<string>& word, string order) {
        vector<int> v(26, 0);
        for(int i=0;i<26;i++){
            v[order[i] - 'a'] = i;
        }
        for(int i=1;i<word.size();i++){
            bool flag = false;
            for(int j=0;j<min(word[i].size(), word[i - 1].size());j++){
                if(v[word[i][j] - 'a'] < v[word[i - 1][j] - 'a']){
                    return false;
                }else if(v[word[i][j] - 'a'] > v[word[i - 1][j] - 'a']){
                    flag = true;
                    break;
                }
            }
            if(!flag && word[i - 1].size() > word[i].size()){
                return false;
            }
        }
        return true;
    }
};