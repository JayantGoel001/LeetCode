class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        int size = nums.size();
        
        while(size != 1){
            int k = 0;
            bool even = true;
            for(int i=0;i<size;i+=2){
                if(even){
                    nums[k++] = min(nums[i], nums[i + 1]);
                }else{
                    nums[k++] = max(nums[i], nums[i + 1]);
                }
                even = !even;
            }
            
            size /= 2;
        }
        return nums[0];
    }
};