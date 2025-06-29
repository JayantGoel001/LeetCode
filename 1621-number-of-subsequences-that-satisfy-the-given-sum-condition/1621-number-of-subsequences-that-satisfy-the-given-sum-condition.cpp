class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        int count = 0;
        int MOD = 1e9 + 7;
        int low = 0;
        int high = nums.size() - 1;
        
        vector<int> power(nums.size(), 1);
        
        for(int i=1;i<nums.size();i++){
            power[i] = (power[i - 1] * 2)%MOD;
        }
        while(low <= high){
            if(nums[low] + nums[high] <= target){
                count =  (count + (power[high - low]))%MOD;
                low++;
            }else{
                high--;
            }
        }
        return count;
    }
};