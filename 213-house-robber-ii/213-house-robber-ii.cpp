class Solution {
public:
    int rob(vector<int>& nums) {
        int inc1 = nums[0];
        int exc1 = 0;
        
        for(int i=1;i<nums.size()-1;i++){
            int temp = inc1;
            inc1 = exc1 + nums[i];
            exc1 = max(temp,exc1);
        }
        
        int inc2 = 0;
        int exc2 = 0;
        
        for(int i=1;i<nums.size();i++){
            int temp = inc2;
            inc2 = exc2 + nums[i];
            exc2 = max(temp,exc2);
        }
        return max({inc1,exc1,inc2,exc2});
    }
};