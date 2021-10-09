class Solution {
public:
    bool canConstruct(string &ransomNote, string &magazine) {
        
        int mp[26];
        for(int i=0;i<26;i++){
            mp[i] = 0;
        }
        
        for(auto it : magazine){
            mp[it-'a']++;
        }
        for(auto it : ransomNote){
            mp[it-'a']--;
            if(mp[it-'a'] < 0){
                return false;
            }
        }
        return true;
    }
};