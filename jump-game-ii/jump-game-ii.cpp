class Solution {
public:
    int jump(vector<int>& nums) {
        int size = nums.size();
        
        int count = 0;
        
        int maxi = 0;
        int i = 0;
        int reach = 0;
        while(i < size - 1){
            maxi = max(maxi,nums[i] + i);
            if(i == reach){
                reach = maxi;
                count++;
            }
            i++;
        }
        
        return count;
    }
};