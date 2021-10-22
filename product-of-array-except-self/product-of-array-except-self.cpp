class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> res(size,1);
        
        res[size-1] = nums[size-1];
        
        for(int i=size-2;i>=0;i--){
            res[i] = res[i+1] * nums[i];
        }
        int prod = 1;
        
        for(int i = 0;i<size-1;i++){
            res[i] = res[i+1] * prod;
            prod *= nums[i];
        }
        res[size-1] = prod;
        
        return res;
    }
};