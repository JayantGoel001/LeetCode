class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = INT_MIN;
        int prod = 1;
        for(auto it : nums){
            prod *= it;
            
            maxi = max(maxi,prod);
            
            if(prod == 0){
                prod = 1;
            }
        }
        prod = 1;
        int size = nums.size();
        for(int i=size-1;i>=0;i--){
            prod *= nums[i];
            
            maxi = max(maxi,prod);
            
            if(prod == 0){
                prod = 1;
            }
        }
        return maxi;
    }
};