class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int x = k;
        for(auto it: nums){
            x ^= it;
        }
        int count = 0;
        while(x){
            x &= (x - 1);
            
            count++;
        }
        return count;
    }
};