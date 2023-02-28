class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> mp(26, 0);
        for(auto it : chars){
            mp[it - 'a']++;
        }
        int count = 0;
        for(auto word : words){
            
            bool flag = true;
            for(int i = 0;i < word.size();i++){
                mp[word[i] - 'a']--;
                
                if(mp[word[i] - 'a'] < 0){
                    flag = false;
                }
            }
            if(flag){
                count += (int)word.size();
            }
            for(int i = word.size() - 1;i >= 0;i--){
                mp[word[i] - 'a']++;
            }
        }
        return count;
    }
};