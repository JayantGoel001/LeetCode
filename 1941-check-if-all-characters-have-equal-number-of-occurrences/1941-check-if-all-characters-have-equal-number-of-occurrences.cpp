class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char,int> mp;
        
        for(auto it : s){
            mp[it]++;
        }
        int initial = 0;
        for(auto it : mp){
            if(initial == 0){
                initial = it.second;
            }else if(initial != it.second){
                return false;
            }
        }
        return true;
    }
};