class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int> loose;
        map<int,int> mp;
        for(auto it : matches){
            loose[it[1]]++;
            mp[it[0]]++;
            mp[it[1]]++;
        }
        vector<vector<int>> v(2);
        for(auto it : mp){
            if(loose[it.first] == 0){
                v[0].push_back(it.first);
            }else if(loose[it.first] == 1){
                v[1].push_back(it.first);
            }
        }
        return v;
    }
};