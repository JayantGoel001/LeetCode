class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();
        int i = 1;
        int count = 0;
        while(i<n){
            int prev = nums[i - 1];
            int curr = nums[i];
            while(i + 1 < n && nums[i] == nums[i + 1]){
                i++;
            }
            if(i + 1 < n){
                int next = nums[i + 1];
                if((prev < curr && curr > next) || (prev > curr && curr < next)){
                    count++;
                }
            }
            i++;
        }
        return count;
    }
};