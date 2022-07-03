class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        for(int i=1;i<cost.size();i++){
            cost[i] += min(cost[i - 1], i > 1 ? cost[i - 2] : 0);
        }
        
        return min(cost[cost.size() - 1], cost[cost.size() - 2]);
    }
};