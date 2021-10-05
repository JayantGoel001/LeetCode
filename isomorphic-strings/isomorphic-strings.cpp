class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> mp;
        map<char,char> rmp;
        
        int ss = s.size();
        int st = t.size();
        
        for(int i = 0;i<ss;i++){
            if((mp.find(s[i]) != mp.end() && mp[s[i]] != t[i]) || (rmp.find(t[i]) != rmp.end() && rmp[t[i]] != s[i])){
                return false;
            }
            mp[s[i]] = t[i];
            rmp[t[i]] = s[i];
        }
        return true;
    }
};