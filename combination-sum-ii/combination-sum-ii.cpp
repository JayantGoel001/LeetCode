class Solution {
public:
    vector<vector<int>> v;
    
    void generateComb(unordered_map<int,int> mp, int target,vector<int> &_v){
        if(target == 0){
            v.push_back(_v);
        }else if(target > 0){
            for(auto it : mp){
                if(it.second > 0){
                    mp[it.first]--;
                    _v.push_back(it.first);
                    
                    generateComb(mp,target - it.first,_v);
                    
                    _v.pop_back();
                }
                mp[it.first]=0;
            }
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& cand, int target) {
        unordered_map<int,int> mp;
        for(auto it : cand){
            mp[it]++;
        }
        vector<int> _v;
        generateComb(mp,target,_v);
        return v;
    }
};