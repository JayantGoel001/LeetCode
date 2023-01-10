class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for(auto num : nums){
            count += (int)log10(num) % 2;
        }
        return count;
    }
};