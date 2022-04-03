class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int> loose;
        set<int> s;
        for(auto it : matches){
            loose[it[1]]++;
            s.insert(it[0]);
            s.insert(it[1]);
        }
        vector<vector<int>> v(2);
        for(auto it : s){
            if(loose[it] == 0){
                v[0].push_back(it);
            }else if(loose[it] == 1){
                v[1].push_back(it);
            }
        }
        return v;
    }
};