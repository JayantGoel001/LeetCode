class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> mp;
        
        for(auto it : strs){
            string str2 = it;
            sort(str2.begin(),str2.end());
            
            mp[str2].push_back(it);
        }
        vector<vector<string>> v;
        for(auto it : mp){
            v.push_back(it.second);
        }
        return v;
    }
};