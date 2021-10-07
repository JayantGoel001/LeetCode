class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int size = pattern.size();
        
        unordered_map<char,string> mp;
        unordered_map<string,char> rmp;
        vector<string> v;
        
        string str = "";
        for(auto it : s){
            if(it == ' '){
                v.push_back(str);
                str = "";
            }else{
                str += it;
            }
        }
        v.push_back(str);
        
        if(v.size() != pattern.size()){
            return false;
        }
        
        for(int i=0;i<size;i++){
            if((mp[pattern[i]]!="" && mp[pattern[i]] != v[i]) || (rmp[v[i]] && rmp[v[i]] != pattern[i])){
                return false;
            }
            mp[pattern[i]] = v[i];
            rmp[v[i]] = pattern[i];
        }
        return true;
    }
};