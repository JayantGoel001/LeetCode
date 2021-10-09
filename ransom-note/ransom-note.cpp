class Solution {
public:
    bool canConstruct(string &ransomNote, string &magazine) {
        unordered_map<char,int> mp;
        
        for(auto it : magazine){
            mp[it]++;
        }
        for(auto it : ransomNote){
            mp[it]--;
            if(mp[it] < 0){
                return false;
            }
        }
        return true;
    }
};