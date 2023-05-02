class Solution {
public:
    int arraySign(vector<int>& nums) {
        int res = 1;
        for(auto it : nums){
            if(it == 0){
                return 0;
            }
            res *= it > 0 ? 1 : -1;
        }
        return res;
    }
};