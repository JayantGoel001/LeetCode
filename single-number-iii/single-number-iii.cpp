class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long int x = 0;
        for(auto it : nums){
            x ^= it;
        }
        long int mask = x & (-x);
        
        int num1 = 0;
        int num2 = 0;
        
        for(auto it : nums){
            if(mask & it){
                num1 ^= it;
            }else{
                num2 ^= it;
            }
        }
        return {num1,num2};
    }
};