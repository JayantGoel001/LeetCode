class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        int ar[26];
        for(int i=0;i<26;i++){
            ar[i] = 0;
        }
        for(auto it : strs){
            for(auto s : it){
                ar[s - 'a']++;
            }
            string str = "";
            for(int i=0;i<26;i++){
                if(ar[i] != 0){
                    str += (i + 'a');
                    str += (ar[i] + '0');
                    ar[i] = 0;
                }
            }
            mp[str].push_back(it);
        }
        vector<vector<string>> v;
        for(auto it : mp){
            v.push_back(it.second);
        }
        return v;
    }
};