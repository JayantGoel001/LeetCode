class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        
        int maxi = 0;
        int reach = 0;
        int size = nums.size();
        for(int i=0;i<size-1;i++){
            maxi = max(maxi,nums[i] + i);
            if(reach == i){
                jumps++;
                reach = maxi;
            }
        }
        return jumps;
    }
};