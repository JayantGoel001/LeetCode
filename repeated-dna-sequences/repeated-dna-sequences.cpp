class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int size = s.size();
        vector<string> v;
        
        unordered_map<string,int> mp;
        for(int i=0;i<size-9;i++){
            mp[s.substr(i,10)]++;
        }
        for(auto it : mp){
            if(it.second > 1){
                v.push_back(it.first);
            }
        }
        return v;
    }
};