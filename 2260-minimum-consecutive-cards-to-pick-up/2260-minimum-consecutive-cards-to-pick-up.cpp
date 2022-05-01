class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<cards.size();i++){
            mp[cards[i]].push_back(i);
        }
        int mini = INT_MAX;
        for(auto it : mp){
            if(it.second.size() >= 2){
                for(int i = 0;i < it.second.size() - 1;i++){
                    mini = min(mini, it.second[i + 1] - it.second[i] + 1);
                }
            }
        }
        return mini == INT_MAX ? -1 : mini;
    }
};