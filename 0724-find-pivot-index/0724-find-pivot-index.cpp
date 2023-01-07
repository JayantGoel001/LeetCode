class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        
        for(auto it : nums){
            sum += it;
        }
        int lsum = 0;
        for(int i=0;i<nums.size();i++){
            int it = nums[i];
            sum -= it;
            
            if(lsum == sum){
                return i;
            }
            lsum += it;
        }
        return -1;
    }
};