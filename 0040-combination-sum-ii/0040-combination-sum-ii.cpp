class Solution {
public:
    vector<vector<int>> v;
    void generateComb(int target,vector<int> &temp,unordered_map<int,int> mp){
        if(target < 0){
            return;
        }
        if(target == 0){
            v.push_back(temp);
        }else{
            for(auto it : mp){
                if(it.second > 0){
                    mp[it.first]--;
                    temp.push_back(it.first);
                    
                    generateComb(target - it.first,temp,mp);
                    
                    temp.pop_back();
                }
                mp[it.first] = 0;
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& cand, int target) {
        unordered_map<int,int> mp;
        for(auto it : cand){
            mp[it]++;
        }
        vector<int> temp;
        generateComb(target,temp,mp);
        return v;
    }
};