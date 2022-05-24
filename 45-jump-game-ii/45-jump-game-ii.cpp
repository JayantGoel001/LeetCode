class Solution {
public:
    int jump(vector<int>& nums) {
        int count = 0;
        int maxi = 0;
        int reach = 0;
        
        for(int i=0;i<nums.size()-1;i++){
            maxi = max(maxi,nums[i] + i);
            if(reach == i){
                count++;
                reach = maxi;
            }
        }
        return count;
    }
};