class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        if(k<=1){
            return 0;
        }
        int prod = 1;
        int count = 0;
        int low = 0;
        int size = nums.size();
        for(int i =0;i<size;i++){
            prod *= nums[i];
            while(prod >= k){
                prod/=nums[low++];
            }
            count += i - low + 1;
        }
        return count;
    }
};