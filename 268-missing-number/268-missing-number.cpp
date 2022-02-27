class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        
        int sum = 0;
        for(auto it : nums){
            sum += it;
        }
        
        int x = n * (n + 1)/2 - sum;
        return x;
    }
};