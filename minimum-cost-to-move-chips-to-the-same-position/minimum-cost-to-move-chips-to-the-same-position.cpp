class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int cnt[2] = {};
        for (auto p : position){
             ++cnt[p % 2];
        };
        return min(cnt[0], cnt[1]);
    }
};