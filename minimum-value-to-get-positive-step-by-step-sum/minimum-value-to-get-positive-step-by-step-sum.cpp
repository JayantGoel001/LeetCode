class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int size = nums.size();
        
        for(int i=1;i<size;i++){
            nums[i] += nums[i-1];
        }
        int mini = INT_MAX;
        
        for(int i=0;i<size;i++){
            if(nums[i] < 0){
                mini = min(mini,nums[i]-1);
            }
        }
        return mini == INT_MAX ? 1 : -mini;
    }
};