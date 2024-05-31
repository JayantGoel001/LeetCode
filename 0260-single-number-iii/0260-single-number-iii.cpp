class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x = 0;
        for(auto it : nums) {
            x ^= it;
        }
        
        int temp = x;
        int i = 0;
        while((temp & 1) == 0) {
            i++;
            temp >>= 1;
        }
        
        int first = 0;
        for(auto it : nums){
            if(((it >> i) & 1) == 1) {
                first ^= it;
            }
        }
        
        return {first, first ^ x};
    }
};