class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long sum = 0;
        int count = 0;
        for(auto it : nums){
            if(it == 0){
                count++;
            }else{
                sum += ((long long)count * (count + 1))/2;
                count = 0;
            }
        }
        sum += ((long long)count * (count + 1))/2;
        return sum;
    }
};