class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k%nums.size();
        std::rotate(nums.begin(),nums.begin() + nums.size() - k ,nums.end());
    }
};