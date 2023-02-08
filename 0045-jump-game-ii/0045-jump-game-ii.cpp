class Solution {
public:
    int jump(vector<int>& nums) {
        int count = 0;
        int jump = 0;
        int end = 0;
        
        for(int i=0;i<nums.size() - 1;i++){
            jump = max(jump, i + nums[i]); 
            if(i == end){
                count ++;
                end = jump;
            }
        }
        return count;
    }
};