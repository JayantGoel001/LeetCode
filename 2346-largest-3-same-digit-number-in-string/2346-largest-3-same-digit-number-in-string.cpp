class Solution {
public:
    string largestGoodInteger(string nums) {
        char maxi = '-';
        for(int i=0;i<nums.size()-2;i++){
            if(nums[i] == nums[i+1] && nums[i+1] == nums[i+2]){
                maxi = max(maxi,nums[i]);
            }
        }
        string res = "";
        res += maxi;
        res += maxi;
        res += maxi;
        return maxi == '-' ? "" : res;
    }
};