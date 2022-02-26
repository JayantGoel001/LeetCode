class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> right(n,1);
        
        int prod = 1;
        right[n-1] = nums[n-1];
        
        for(int i=n-2;i>=0;i--){
            right[i] = nums[i] * right[i + 1];
        }
        for(int i=0;i<n-1;i++){
            int temp = nums[i];
            nums[i] = prod * right[i+1];
            prod *= temp;
        }
        nums[n - 1] = prod;
        return nums;
    }
};