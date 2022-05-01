class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int,int> mp;
        int mini = INT_MAX;
        for(int i=0;i<cards.size();i++){
            if(mp[cards[i]] != 0){
                mini = min(mini,i + 1 - mp[cards[i]] + 1);
            }   
            mp[cards[i]] = i + 1;
        }
        return mini == INT_MAX ? -1 : mini;
    }
};