class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int sum1 = 0;
        int sum2 = 0;
        int sum = 0;
        
        int maxSum = INT_MIN;
        int minSum = INT_MAX;
        
        for(auto it : nums){
            sum += it;
        }
        for(auto it : nums){
            sum1 += it;
            sum2 += it;
            
            maxSum = max(maxSum,sum1);
            minSum = min(minSum,sum2);
            
            if(sum1 < 0){
                sum1 = 0;
            }
            if(sum2 > 0){
                sum2 = 0;
            }
        }
        if(minSum == sum){
            return maxSum;
        }
        return max(maxSum,sum - minSum);
    }
};