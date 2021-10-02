class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        int maxi = 0;
        for(int i=0;i<size;i++){
            if(maxi < i){
                return false;
            }
            maxi = max(maxi,i + nums[i]);
        }
        return true;
    }
};