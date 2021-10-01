class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        for(auto it : nums){
            sum+=it;
        }
        int size = nums.size();
        return (size * (size + 1))/2 - sum;
    }
};