class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int len = nums.size();
        
        int sum = 0;
        int patch = 0;
        int i =0;
        while(sum<n){
            if(i != len && nums[i] <= sum + 1){
                sum += nums[i];
                i++;
            }else{
                patch++;
                if( sum > INT_MAX/2){
                    sum = INT_MAX;
                }else{
                    sum = 2 * sum + 1;
                }
            }
        }
        return patch;
    }
};