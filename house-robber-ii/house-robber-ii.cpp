class Solution {
public:
    int rob(vector<int>& nums) {
        int inc = nums[0];
        int exc = 0;
        
        int n = nums.size();
        for(int i=1;i<n-1;i++){
            int temp = inc;
            inc = exc + nums[i];
            
            exc = max(exc,temp);
        }
        int max1 = max(inc,exc);
        inc = 0;
        exc = 0;
        for(int i=1;i<n;i++){
            int temp = inc;
            inc = exc + nums[i];
            exc = max(temp,exc);
        }
        return max({max1,inc,exc});
    }
};