class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0.0;
        double res = -INT_MAX;
        
        for(int i=1;i<=nums.size();i++) {
            sum += nums[i - 1];
            if (i >= k) {
                res = max(res, sum / k);
                sum -= nums[i - k];
            }
        }
        return res;
    }
};