class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int k = 1001;
        for(int i=0;i<nums.size();i++){
            nums[i] = k * nums[i];
        }
        int even = 0;
        int odd = 1;
        for(int i=0;i<nums.size();i++){
            if((nums[i]/k) % 2 == 0){
                nums[even] += nums[i]/k;
                even += 2;
            }else{
                nums[odd] += nums[i]/k;
                odd += 2;
            }
        }
        for(int i=0;i<nums.size();i++){
            nums[i] %= k;
        }
        return nums;
    }
};