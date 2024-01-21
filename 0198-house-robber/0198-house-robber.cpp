class Solution {
public:
    int rob(vector<int>& nums) {
        int inc = 0;
        int exc = 0;
        
        for(auto it : nums){
            int temp = inc;
            inc = exc + it;
            exc = max(temp,exc);
        }
        
        return max(inc,exc);
    }
};