class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxSum = 0;
        
        for(auto acc : accounts){
            int sum = 0;
            for(auto it : acc){
                sum += it;
            }
            maxSum = max(maxSum,sum);
        }
        return maxSum;
    }
};