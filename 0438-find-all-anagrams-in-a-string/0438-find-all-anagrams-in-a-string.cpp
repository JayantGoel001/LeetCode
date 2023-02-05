class Solution {
public:
    bool check(vector<int> &mp){
        for(int i=0;i<26;i++){
            if(mp[i] != 0){
                return false;
            }
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int> v;
        if(p.size() > s.size()){
            return v;
        }
        
        vector<int> mp(26, 0);
        for(auto it : p){
            mp[it - 'a']++;
        }
        for(int i=0;i<p.size();i++){
            mp[s[i]-'a']--;
        }
        if(check(mp)){
            v.push_back(0);
        }
        for(int i=p.size();i<s.size();i++){
            mp[s[i] - 'a']--;
            mp[s[i - p.size()] - 'a']++;
            
            if(check(mp)){
                v.push_back(i - p.size() + 1);
            }
        }
        return v;
    }
};