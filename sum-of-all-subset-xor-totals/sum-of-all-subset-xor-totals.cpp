class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int sum =0;
        
        for(auto it : nums){
            sum |= it;
        }
        
        return sum<< (nums.size() - 1);
    }
};