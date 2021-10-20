class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxI1 = 0;
        int maxI2 = 0;
        for(auto it : nums){
            if(maxI1 <= it){
                maxI2 = maxI1;
                maxI1 = it;
            }
            if(maxI2 <= it && maxI1 != it){
                maxI2 = it;
            }
        }
        return (maxI1 - 1) * (maxI2 - 1);
    }
};