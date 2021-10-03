class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        
        int minDiff = INT_MAX;
        int sum = INT_MAX;
        int size = nums.size();
        
        for(int i=0;i<size;i++){
            int j = i + 1;
            int k = size - 1;
            
            while(j<k){
                if(minDiff > abs(nums[i] + nums[j] + nums[k] - target)){
                    minDiff = abs(nums[i] + nums[j] + nums[k] - target);
                    sum = nums[i] + nums[j] + nums[k];
                }
                
                if(nums[j] + nums[k] < target - nums[i]){
                    j++;
                }else{
                    k--;
                }
            }
        }
        return sum;
    }
};