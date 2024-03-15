class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int length = nums.size();
        vector<int> products(length);

        int prefixProduct = 1;
        for (int i = 0; i < length; i++) {
            products[i] = prefixProduct;
            prefixProduct *= nums[i];
        }

        int suffixProduct = 1;
        for (int i = length - 1; i >= 0; i--) {
            products[i] *= suffixProduct;
            suffixProduct *= nums[i];
        }

        return products;
    }
};