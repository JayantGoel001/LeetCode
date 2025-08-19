class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long sum = 0;
        int count = 0;
        for(auto it : nums){
            if(it == 0){
                count++;
            }else{
                count = 0;
            }
            sum += (long long)count;
        }
        return sum;
    }
};