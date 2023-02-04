class Solution {
public:
    bool checkMap(vector<int> &v){
        for(int i=0;i<26;i++){
            if(v[i] != 0){
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()){
            return false;
        }
        
        vector<int> mp(26, 0);
        
        for(auto it : s1){
            mp[it - 'a']++;
        }
        for(int i=0;i<s1.size();i++){
            mp[s2[i] - 'a']--;
        }
        if(checkMap(mp)){
            return true;
        }
        for(int i=s1.size();i<s2.size();i++){
            mp[s2[i] - 'a']--;
            mp[s2[i - s1.size()] - 'a']++;
            
            if(checkMap(mp)){
                return true;
            }
        }
        return false;
    }
};