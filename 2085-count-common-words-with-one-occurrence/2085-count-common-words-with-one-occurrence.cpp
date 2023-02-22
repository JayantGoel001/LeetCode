class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> mp;
        
        for(auto it : words1){
            mp[it]++;
        }
        int count = 0;
        for(auto word : words2){
            if(mp[word] <= 1){
                mp[word]--;
            }
        }
        for(auto it : mp){
            count += it.second == 0;
        }
        return count;
    }
};