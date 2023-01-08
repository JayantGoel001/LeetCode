class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pos = 0;
        int neg = 0;
        
        for(auto it : nums){
            pos += it > 0;
            neg += it < 0;
        }
        return max(pos, neg);
    }
};