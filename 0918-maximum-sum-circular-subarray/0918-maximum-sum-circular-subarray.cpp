class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int sum = 0;
        
        int maxSum = INT_MIN;
        int minSum = INT_MAX;
        int curMax = 0;
        int curMin = 0;
        
        for(auto it : nums){
            curMax += it;
            curMin += it;
            
            maxSum = max(maxSum, curMax);
            minSum = min(minSum, curMin);
            
            if(curMax < 0){
                curMax = 0;
            }
            if(curMin > 0){
                curMin = 0;
            }
            
            sum += it;
        }
        return sum == minSum ? maxSum : max(maxSum, sum - minSum);
    }
};