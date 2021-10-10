class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int maxLen = 0;
        int size = nums.size();
        int pos = -1;
        int neg = -1;
        int sign = 1;
        for(int i=0;i<size;i++){
            if(nums[i] == 0){
                pos = i;
                neg = -1;
                sign = 1;
            }else{
                sign = nums[i] > 0 ? sign : -sign;
                
                if(sign < 0){
                    if(neg == -1){
                        neg = i;
                    }
                    maxLen = max(maxLen,i - neg);
                }else{
                    maxLen = max(maxLen,i - pos);
                }
            }
        }
        return maxLen;
    }
};