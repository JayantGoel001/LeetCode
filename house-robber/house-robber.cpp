class Solution {
public:
    int rob(vector<int>& nums) {
        int inc = 0;
        int exc = 0;
        
        int size = nums.size();
        for(int i=0;i<size;i++){
            int temp = inc;
            
            inc = exc + nums[i];
            exc = max(temp,exc);
        }
        return max(inc,exc);
    }
};