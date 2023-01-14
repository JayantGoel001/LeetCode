class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0;
        
        int maxi = nums[nums.size() - 1];
        int count = 0;
        int sum = 0;
        while(i < nums.size() && maxi > 0){
            nums[i] -= sum;
            maxi -= nums[i];
            sum += nums[i];
            count += (nums[i] !=0);
            i++;
            
        }
        return count;
    }
};