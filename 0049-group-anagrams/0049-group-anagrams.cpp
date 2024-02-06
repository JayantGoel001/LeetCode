class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> v;
        
        unordered_map<string,vector<string>> mp;
        for(auto it : strs){
            int ar[26] ={0};
            for(auto it2 : it){
                ar[it2 - 'a']++;
            }
            
            string s = "";
            
            for(int i=0;i<26;i++){
                s += (i + 'a');
                s += (ar[i] + '0');
            }
            
            mp[s].push_back(it);
        }
        for(auto it : mp){
            v.push_back(it.second);
        }
        return v;
    }
};