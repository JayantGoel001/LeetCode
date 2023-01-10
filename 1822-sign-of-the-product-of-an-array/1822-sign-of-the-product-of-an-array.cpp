class Solution {
public:
    int arraySign(vector<int>& nums) {
        int neg = 0;
        for(auto it : nums){
            neg += it < 0;
            if(it == 0){
                return 0;
            }
        }
        return neg%2? -1 : 1;
    }
};