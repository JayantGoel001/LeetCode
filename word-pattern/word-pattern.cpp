class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string,char> rmp;
        unordered_map<char,string> mp;
        
        int size = pattern.size();
        int k = 0;
        int ss = s.size();
        vector<string> v;
        string str = "";
        while(k<ss){
            if(s[k] != ' '){
                str += s[k];
            }else{
                v.push_back(str);
                str = "";
            }
            k++;
        }
        v.push_back(str);
        if(v.size() != size){
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