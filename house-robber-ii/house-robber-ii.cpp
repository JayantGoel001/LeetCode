class Solution {
public:
    int rob(vector<int>& nums) {
        int inc = nums[0];
        int exc = 0;
        
        int size = nums.size();
        for(int i = 1;i<size-1;i++){
            int temp = inc;
            inc = exc + nums[i];
            
            exc = max(exc,temp);
        }
        
        int output = max(inc,exc);
        
        inc = 0;
        exc = 0;
        
        for(int i=1;i<size;i++){
            int temp = inc;
            inc = exc + nums[i];
            
            exc = max(exc,temp);
        }
        
        return max(output,max(inc,exc));
    }
};