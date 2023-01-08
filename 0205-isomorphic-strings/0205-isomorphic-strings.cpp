class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<int,int> mp, rmp;
        
        for(int i=0;i<s.size();i++){
            if(mp[s[i]] == 0){
                mp[s[i]] = t[i];
            }
            if(rmp[t[i]] == 0){
                rmp[t[i]] = s[i];
            }
            if(mp[s[i]] != t[i] || rmp[t[i]] != s[i]){
                return false;
            }
        }
        return true;
    }
};