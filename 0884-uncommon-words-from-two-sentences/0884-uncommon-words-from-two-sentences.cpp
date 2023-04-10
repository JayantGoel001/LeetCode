class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> mp;
        string s = "";
        for(auto it : s1){
            if(it == ' '){
                mp[s]++;
                s = "";
            }else{
                s += it;
            }
        }
        mp[s]++;
        s = "";
        for(auto it : s2){
            if(it == ' '){
                mp[s]++;
                s = "";
            }else{
                s += it;
            }
        }
        mp[s]++;
        
        vector<string> v;
        for(auto it : mp){
            if(it.second == 1){
                v.push_back(it.first);
            }
        }
        return v;
    }
};