class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        vector<unordered_set<string>> v(26);
        
        for(auto idea : ideas){
            v[idea[0] - 'a'].insert(idea.substr(1));
        }
        long long res = 0;
        
        for(int i=0;i<25;i++){
            for(int j = i + 1;j < 26;j++){
                int same = 0;
                for(auto it : v[i]){
                    same += v[j].count(it);
                }
                
                res += (long long)2 * (v[i].size() - same) * (v[j].size() - same);
            }
        }
        return res;
    }
};