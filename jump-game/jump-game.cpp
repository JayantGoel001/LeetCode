class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxi = 0;
        
        int size = nums.size();
        for(int i = 0;i<size;i++){
            if(maxi < i){
                return false;
            }
            
            maxi = max(maxi,i + nums[i]);
        
        }
        return true;
    }
};