class Solution {
public:
    int GCD(int A,int B){
        if(B == 0){
            return A;
        }
        return GCD(B,A%B);
    }
    
    bool isGoodArray(vector<int>& nums) {
        int res = nums[0];
        
        for(auto it : nums){
            res = GCD(res,it);
        }
        return res == 1;
    }
};